#!/usr/bin/env python3
"""
bode_graph_paper_multiples_of_omega.py

Create blank Bode graph paper sized 7" x 5" with x-axis labeled as multiples
of a symbolic omega (e.g. \omega_0 or \omega).

By default the script treats the "reference" omega (omega_ref) as 1 in the
numeric coordinate system, and labels ticks as multiples of that symbol.
If you want the numeric grid to represent a different numeric omega_ref
(e.g. omega_ref = 2*pi*1000), scale freq_min/freq_max accordingly or set
omega_value (see comments below).

Outputs: PDF (vector) and PNG (raster) in the current folder.
"""

import numpy as np
import matplotlib.pyplot as plt
from matplotlib.ticker import LogLocator, NullFormatter, MultipleLocator, FormatStrFormatter

def decade_ticks(freq_min, freq_max):
    """Return list of major decade tick positions (10**d) that lie inside range."""
    dmin = int(np.floor(np.log10(freq_min)))
    dmax = int(np.ceil(np.log10(freq_max)))
    return [10**d for d in range(dmin, dmax+1)]

def label_for_decade(value, omega_symbol=r"\omega_0"):
    """
    Format a tick label for a decade value (value is a power-of-ten: 10**d).
    Returns a LaTeX string such as:
        10^{-2}\omega_0 or \omega_0  (when d == 0)
    For 10^1 -> 10\omega_0  (no exponent)
    """
    # compute exponent (should be integer)
    d = int(round(np.log10(value)))
    if d == 0:
        return rf"${omega_symbol}$"
    elif d == 1:
        return rf"$10{omega_symbol}$"
    else:
        return rf"$10^{{{d}}}{omega_symbol}$"

def make_bode_graph_paper(
    filename_base="bode_graph_paper_7x5",
    figsize=(7, 5),
    # frequency bounds are numeric; by default they assume omega_ref == 1
    freq_min=0.1,
    freq_max=1000.0,
    omega_symbol=r"\omega_0",
    mag_ylim=(-60, 20),
    mag_step=10,
    phase_ylim=(-270, 90),
    phase_step=30,
    dec_minor_subs=[2,3,4,5,6,7,8,9],
):
    """
    Create and save the blank Bode graph paper.

    IMPORTANT:
      - This script treats the reference omega (omega_ref) as numeric 1.
        If you want the numeric grid to correspond to a real omega0 value (e.g. 2*pi*1000),
        either:
          * set freq_min/freq_max scaled by that value, OR
          * multiply tick positions by that value (more advanced).
        For pure symbolic multiple labels, leave omega_ref == 1 and the labels will read
        as multiples of the symbol (omega_symbol).
    """
    # Create figure with constrained_layout to avoid tight_layout warnings
    fig = plt.figure(figsize=figsize, constrained_layout=True)
    gs = fig.add_gridspec(2, 1, height_ratios=(2, 1), hspace=0.06)

    # Magnitude axis
    ax_mag = fig.add_subplot(gs[0, 0])
    ax_mag.set_xscale("log")
    ax_mag.set_xlim(freq_min, freq_max)
    ax_mag.set_ylim(*mag_ylim)

    # X major/minor locators (decades + subs)
    ax_mag.xaxis.set_major_locator(LogLocator(base=10.0, numticks=20))
    ax_mag.xaxis.set_minor_locator(LogLocator(base=10.0, subs=dec_minor_subs, numticks=200))
    ax_mag.xaxis.set_minor_formatter(NullFormatter())

    # Y ticks & grid
    ax_mag.yaxis.set_major_locator(MultipleLocator(mag_step))
    ax_mag.yaxis.set_major_formatter(FormatStrFormatter("%d"))
    ax_mag.grid(which="major", axis="y", linestyle="--", linewidth=0.6, alpha=0.9)

    # Vertical gridlines for decades (major) and subdecades (minor)
    ax_mag.grid(which="major", axis="x", linestyle="-", linewidth=0.8, alpha=0.7)
    ax_mag.grid(which="minor", axis="x", linestyle=":", linewidth=0.5, alpha=0.4)

    # 0 dB reference
    if mag_ylim[0] < 0 < mag_ylim[1]:
        ax_mag.axhline(0, linewidth=0.8, alpha=0.6)

    ax_mag.set_ylabel("Magnitude (dB)", labelpad=6)
    ax_mag.set_xticklabels([])  # no x labels on top panel

    # Phase axis (shared x)
    ax_ph = fig.add_subplot(gs[1, 0], sharex=ax_mag)
    ax_ph.set_xscale("log")
    ax_ph.set_xlim(freq_min, freq_max)
    ax_ph.set_ylim(*phase_ylim)

    ax_ph.xaxis.set_major_locator(LogLocator(base=10.0, numticks=20))
    ax_ph.xaxis.set_minor_locator(LogLocator(base=10.0, subs=dec_minor_subs, numticks=200))
    ax_ph.xaxis.set_minor_formatter(NullFormatter())

    ax_ph.yaxis.set_major_locator(MultipleLocator(phase_step))
    ax_ph.yaxis.set_major_formatter(FormatStrFormatter("%d"))
    ax_ph.grid(which="major", axis="y", linestyle="--", linewidth=0.6, alpha=0.9)
    ax_ph.grid(which="major", axis="x", linestyle="-", linewidth=0.8, alpha=0.7)
    ax_ph.grid(which="minor", axis="x", linestyle=":", linewidth=0.5, alpha=0.4)

    # faint reference horizontal lines at typical phase anchors
    for val in (-180, -90, 0, 90):
        if phase_ylim[0] < val < phase_ylim[1]:
            ax_ph.axhline(val, linewidth=0.5, alpha=0.35)

    ax_ph.set_ylabel("Phase (°)", labelpad=6)
    ax_ph.set_xlabel("Frequency (rad/s)")

    # Build decade ticks inside freq range and label them as multiples of omega_symbol
    majors = decade_ticks(freq_min, freq_max)
    ax_ph.set_xticks(majors)
    ax_ph.set_xticklabels([label_for_decade(v, omega_symbol=omega_symbol) for v in majors], fontsize=9)

    # Slightly thicker frame lines for print/tracing
    for spine in list(ax_mag.spines.values()) + list(ax_ph.spines.values()):
        spine.set_linewidth(0.6)

    # Save outputs
    pdf_name = f"{filename_base}.pdf"
    png_name = f"{filename_base}.png"
    fig.savefig(pdf_name, bbox_inches="tight", pad_inches=0.02)
    fig.savefig(png_name, dpi=300, bbox_inches="tight", pad_inches=0.02)
    plt.close(fig)
    print(f"Saved {pdf_name} and {png_name} — size {figsize[0]}\" x {figsize[1]}\"")

if __name__ == "__main__":
    # Example usage: symbolic omega_0 ticks from 10^-1 ... 10^3 (these are numeric positions)
    make_bode_graph_paper(
        filename_base="bode_graph_paper_7x5_omega",
        figsize=(14, 10),
        freq_min=1e-2,   # numeric lower bound (assumes omega_ref = 1)
        freq_max=1e3,    # numeric upper bound
        omega_symbol=r"\omega",  # change to r"\omega" if you prefer
        mag_ylim=(-60, 60),
        mag_step=10,
        phase_ylim=(-270, 90),
        phase_step=30,
    )

