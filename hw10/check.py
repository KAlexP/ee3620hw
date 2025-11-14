import numpy as np
import matplotlib.pyplot as plt
from scipy.fft import fft, fftfreq, fftshift

# Parameters
A = 5
T = 3
N = 2048
t = np.linspace(-5, 5, N)
dt = t[1] - t[0]

# Define f(t)
f_t = np.zeros_like(t)
mask = (t >= 0) & (t <= T)
f_t[mask] = (A/T) * t[mask]

# Numerical Fourier Transform
F_f = fftshift(fft(f_t)) * dt
freqs = fftshift(fftfreq(N, dt)) * 2*np.pi  # angular frequency (rad/s)

# Analytical F(ω)
omega = freqs
#F_analytic = (A/T) * ((1 - np.exp(-1j*omega*T)*(1 + 1j*omega*T)) / (omega**2))

F_analytic  = (A/T) * ((3*np.exp(-1j * T * omega))/(-1j*omega) + (1-np.exp(-1j * T * omega))/((1j*omega)**2))

# Plot comparison
plt.figure(figsize=(10,4))
plt.plot(omega, np.abs(F_f), label='|FFT| (numerical)', alpha=0.7)
plt.plot(omega, np.abs(F_analytic), '--', label='|F(ω)| (analytical)', linewidth=2)
plt.legend()
plt.xlabel('ω (rad/s)')
plt.ylabel('|F(ω)|')
plt.title('Fourier Transform Verification')
plt.xlim(-10,10)
plt.grid(True)
plt.show()

