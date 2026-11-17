# FSR-Based Finger-Pinch Controlled Obstacle Navigation

An interactive Unity-based obstacle navigation game that uses an FSR (Force Sensing Resistor) sensor to detect finger pressure and control character jumps in real time through Arduino-based signal processing.

## Live Demo
Here is the game play using live signals
- 🎮 **Gameplay Video:** https://drive.google.com/drive/folders/1gsgSGtGTEdXLlaB4CwKJDTTyt5fOmgc6?usp=sharing

## Features

- Real-time finger-pressure detection using an FSR sensor.
- Arduino-based signal acquisition.
- Noise reduction using digital filtering techniques.
- Individual signal collection and analysis by four team members.
- Comparison of different filtering methods.
- Selection of the most suitable filter based on signal performance.
- Threshold-based finger-pinch detection.
- Serial communication between Arduino and Unity.
- Real-time character jumping and obstacle avoidance.

## Hardware Requirements

- Arduino Uno
- Force Sensing Resistor (FSR)
- Resistors
- Breadboard
- Jumper wires

## Software & Tools

- Arduino IDE
- Unity Game Engine
- C#
- LiveSignals (signal visualization and analysis)

## Signal Processing

- Individual FSR signal acquisition by all four team members.
- Implementation and comparison of different filtering techniques.
- Analysis of raw and filtered signals.
- Evaluation of noise reduction and signal stability.
- Selection of the best-performing filter for the final implementation.

## Working Principle

1. The FSR sensor detects pressure applied through a finger-pinch gesture.
2. Arduino acquires the analog signal.
3. The acquired signal is processed using the selected filtering technique.
4. A threshold detects intentional finger-pinching actions.
5. The processed input is transmitted to Unity through serial communication.
6. The Unity character jumps to avoid obstacles.

## Screenshots

### Hardware Implementation

<img width="400" height="225" alt="image" src="https://github.com/user-attachments/assets/25964113-f0f2-411b-bcc3-0904a0ced128" />


### Unity Game Interface

| Game Environment | Character Jump |
|---|---|
<img width="400" height="225" alt="image" src="https://github.com/user-attachments/assets/13c2f9c8-8c87-48e8-aa42-e5b6eb08db3f" />
<img width="400" height="225" alt="image" src="https://github.com/user-attachments/assets/7f3c89e7-86c7-47e3-96b2-296bf7e07ed3" />
<img width="400" height="225" alt="image" src="https://github.com/user-attachments/assets/6c8c57ce-a11e-4890-92d3-8236410a4d33" />
<img width="400" height="2225" alt="image" src="https://github.com/user-attachments/assets/9088f9d8-b0fd-481f-9dc1-b4fdb7653fc9" />


## Team Members

This project was collaboratively developed by four team members, with individual signal acquisition and filter analysis followed by collaborative filter selection and game integration.

-Eedara Vedha Samhitha (25110112)
-Gajula Anusree (25110114)
-Adarasandi Sai Ashwika (25110010)
-Divya Saini (25110110)

---

**A gesture-controlled gaming experience combining embedded systems, digital signal processing, and Unity game development.**
