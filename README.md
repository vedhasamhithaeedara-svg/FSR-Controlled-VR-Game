# FSR-Based Finger-Pinch Controlled Obstacle Navigation

A gesture-controlled Unity VR game that uses a Force Sensitive Resistor (FSR) sensor to detect finger-pinching actions and control character jumps in real time. The project integrates Arduino-based signal acquisition, digital signal processing, noise filtering, and Unity game development to create an interactive gaming experience.

## Live Demo

Experience the game controlled using real-time FSR signals!
During the reported live test, all faced obstacles were successfully cleared in a single-player run.

- 🎮 **Gameplay Video:** [Watch Project Demonstration](https://youtu.be/AwKPe7O5to8)

## Features

- Real-time finger-pressure detection using an FSR sensor.
- Arduino-based analog signal acquisition.
- Individual signal collection and analysis by four team members.
- Implementation of four different digital filtering techniques.
- FFT-based frequency analysis.
- Comparative evaluation of filtering methods.
- Selection of the best-performing filter based on noise reduction, signal smoothness, and processing delay.
- Threshold-based finger-pinch detection with hysteresis.
- Serial communication between Arduino and Unity.
- Real-time character jumping and obstacle avoidance in a Unity VR environment.

## Hardware Requirements

- Arduino Uno
- Force Sensitive Resistor (FSR)
- 10 kΩ Resistor
- Breadboard
- Jumper wires
- USB cable

## Software & Tools

- Arduino IDE
- Unity Game Engine
- C#
- LiveSignals (signal visualization and analysis)

## Signal Acquisition & Analysis

Four individual FSR datasets were collected by the team members through repeated pressing and releasing of the sensor.

- Sampling frequency: 200 Hz
- Sampling interval: 5 ms
- ADC resolution: 10-bit (0–1023 counts)
- Data format: Time (ms) and sensor value

Each team member independently implemented a different filtering technique on their recorded signal.

| Team Member | Filtering Technique |
|---|---|
| Vedha | Moving Average Filter |
| Ashwika | Median Filter |
| Divya | 2nd-Order Butterworth Low-Pass Filter |
| Anusree | Exponential Moving Average (EMA) |

## Filter Comparison & Selection

All four filtering techniques were tested across all four datasets to evaluate their performance in terms of noise reduction, signal smoothness, peak preservation, and processing delay.

| Filtering Method | Jitter (counts) | Press Roughness (counts) | Added Delay (ms) |
|---|---:|---:|---:|
| Median Filter | 1.94 | 10.5 | 10.6 |
| Moving Average | 1.67 | 2.8 | 10.0 |
| Butterworth | 1.51 | 1.4 | 19.4 |
| EMA | 1.65 | 3.3 | 11.9 |

### Final Selected Filter: Moving Average Filter

The Moving Average Filter was selected as it provided the best overall balance between noise reduction, signal smoothness, peak preservation, and low processing delay.

Key results:

- Reduced press jitter by approximately 49%.
- Reduced press roughness by approximately 80%.
- Preserved signal peaks with only 0.39% peak loss.
- Introduced only 10 ms of measured delay.
- Maintained reliable jump detection across all four datasets.

The final implementation uses a 12-point Moving Average Filter at a sampling frequency of 500 Hz, corresponding to an approximately 24 ms averaging window.

## Frequency Analysis (FFT)

FFT analysis was performed to understand the frequency characteristics of the acquired FSR signals.

- Approximately 95% of the signal power lies below 2 Hz.
- Approximately 99% of the signal power lies below 4 Hz.
- Higher-frequency components primarily represent noise.

The selected 12-point Moving Average Filter has a -3 dB cutoff frequency of approximately 18.5 Hz at 500 Hz sampling frequency, allowing the pressure signal to be preserved while reducing unwanted high-frequency fluctuations.

## Working Principle

1. The FSR sensor detects finger pressure through a voltage-divider circuit.
2. Arduino acquires the analog sensor readings.
3. The Moving Average Filter smooths the acquired signal and reduces noise.
4. A predefined jump threshold detects intentional finger-pinching actions.
5. A release threshold ensures that a new jump is triggered only after the pressure is released.
6. The filtered signal is transmitted to Unity through serial communication.
7. Unity triggers the character's jump to avoid obstacles such as tree logs, water streams, and fire.

### Jump Detection Parameters

| Parameter | Value |
|---|---:|
| Jump Threshold | 150 |
| Release Threshold | 75 |
| Cooldown | 0.05 s |
| Final Sampling Frequency | 500 Hz |
| Serial Baud Rate | 115200 |

## Screenshots

### Hardware Implementation

<p align="center">
  <img src="https://github.com/user-attachments/assets/25964113-f0f2-411b-bcc3-0904a0ced128" width="400" alt="FSR Hardware Setup">
</p>

### Unity Game Interface

<p align="center">
  <img src="https://github.com/user-attachments/assets/13c2f9c8-8c87-48e8-aa42-e5b6eb08db3f" width="400" alt="Game Environment">
  <img src="https://github.com/user-attachments/assets/7f3c89e7-86c7-47e3-96b2-296bf7e07ed3" width="400" alt="Gameplay Screenshot">
</p>

<p align="center">
  <img src="https://github.com/user-attachments/assets/6c8c57ce-a11e-4890-92d3-8236410a4d33" width="400" alt="Obstacle Navigation">
  <img src="https://github.com/user-attachments/assets/9088f9d8-b0fd-481f-9dc1-b4fdb7653fc9" width="400" alt="Character Jump">
</p>

## Team Members

This project was collaboratively developed by four team members. Each member independently collected and analyzed FSR signals using a different filtering technique, followed by comparative evaluation, final filter selection, and game integration.

- Eedara Vedha Samhitha (25110112)
- Gajula Anusree (25110114)
- Adarasandi Sai Ashwika (25110010)
- Divya Saini (25110110)

---

**A collaborative engineering project combining embedded systems, digital signal processing, and interactive VR game development.**
