import numpy as np
import matplotlib.pyplot as plt
from scipy.fft import fft, fftshift, fftfreq

# Parameters
A = 5
alpha = 10          # s^-1
N = 4096            # FFT points
t_min, t_max = -1, 2
t = np.linspace(t_min, t_max, N)
dt = t[1] - t[0]

# Define the function
f = np.zeros_like(t)
mask = (t >= 0) & (t <= 1)
f[mask] = A*(1 - np.exp(-alpha * t[mask]))

# Numerical Fourier transform
F_fft = fftshift(fft(f)) * dt
omega = fftshift(fftfreq(N, dt)) * 2*np.pi  # rad/sec

# Analytical Fourier transform
# F(ω) = A ∫_0^1 (1 - e^{αt}) e^{-jωt} dt
#     = A [ ∫_0^1 e^{-jωt} dt − ∫_0^1 e^{(α - jω)t} dt ]

omega_safe = omega 

I1 = (1-np.exp(-10-1j*omega_safe)) / (alpha + 1j*omega_safe)
I2 = (1+np.exp(-1j*omega_safe)) / (1j*omega_safe)
# I1 = (1 - np.exp(-1j*omega_safe*1)) / (1j*omega_safe)
# I2 = (np.exp((alpha - 1j*omega_safe)*1) - 1) / (alpha - 1j*omega_safe)

F_exact = A * (I1 - I2)

# Plot magnitude comparison
plt.figure(figsize=(10,5))
plt.plot(omega, np.abs(F_fft), label='|FFT| Numeric')
plt.plot(omega, np.abs(F_exact), '--', linewidth=2, label='|Analytic|')
plt.xlim(-50, 50)   # adjust range as needed
plt.xlabel('ω (rad/s)')
plt.ylabel('|F(ω)|')
plt.grid(True)
plt.legend()
plt.title('Fourier Transform Check')
plt.show()
