import matplotlib.pyplot as plt
import numpy as np

data = [0x55, 0xA0, 0xF8]

def encode_nrzl(data):
    nrzl_signal = []
    for byte in data:
        for bit in range(7, -1, -1):
            bit_val = (byte >> bit) & 0x01
            nrzl_signal.append(bit_val)
    return nrzl_signal

def encode_nrzi(data):
    nrzi_signal = []
    last_bit = 0
    for byte in data:
        for bit in range(7, -1, -1):
            bit_val = (byte >> bit) & 0x01
            if bit_val:
                last_bit = 1 - last_bit
            nrzi_signal.append(last_bit)
    return nrzi_signal

# Convert data to binary representation for annotation
binary_data = ''.join(f"{byte:08b}" for byte in data)

# Generate signals
nrzl_signal = encode_nrzl(data)
nrzi_signal = encode_nrzi(data)

# Plotting
time_nrzl = np.arange(len(nrzl_signal))
time_nrzi = np.arange(len(nrzi_signal))

plt.figure(figsize=(14, 8))

## NRZ-L
plt.subplot(2, 1, 1)
plt.step(time_nrzl, nrzl_signal, where="post", label="NRZ-L Signal")
plt.title("NRZ-L Encoding with Binary Data")
plt.ylabel("Signal Level")
plt.xlabel("Time")
plt.ylim(-0.5, 1.5)
plt.grid(True)
plt.legend()

for i, bit in enumerate(binary_data):
    plt.text(i, 1.1, bit, ha="center", fontsize=8, color="blue")

## NRZI 
plt.subplot(2, 1, 2)
plt.step(time_nrzi, nrzi_signal, where="post", label="NRZI Signal", color="orange")
plt.title("NRZI Encoding with Binary Data")
plt.ylabel("Signal Level")
plt.xlabel("Time")
plt.ylim(-0.5, 1.5)
plt.grid(True)
plt.legend()

for i, bit in enumerate(binary_data):
    plt.text(i, 1.1, bit, ha="center", fontsize=8, color="blue")

plt.tight_layout()
plt.savefig("encodings_with_binary.png")
plt.show()
