# UE_Cpp_Motion-Control-Media-Art

A quick prototype of motion-controlled media art in Unreal Engine, utilizing the OSC protocol implemented in C++ for greater memory management and flexibility, building on concepts from a tutorial by Yu Fujishiro.

> **Disclaimer**: This project is based on a tutorial series available [here](https://www.youtube.com/playlist?list=PLvSZaVrgRBTqme58DCqOy7xKsulJzqtXb).

## About the Project

This Unreal Engine project utilizes Open Sound Control (OSC) to enable interactive media art, controlled by mobile device motion data. Originally designed in Blueprints, this project quickly replicates the OSC protocol implementation in C++. Please note that this project does not follow specific coding patterns, as adhering to them is beyond the scope of this development.

## Getting Started

To set up and run the project, follow these steps:

### Prerequisites

- Unreal Engine
- ZIG SIM app installed on your phone

### Setup Instructions

1. **Download the ZIG SIM App**  
   Install the app on your phone from the appropriate app store.

2. **Connect Your Phone to Your System**  
   Connect your phone to your computer's hotspot.

3. **Configure ZIG SIM Settings**  
   - Set the **Port** to `1234`.
   - Set the **IP Address** to your computer's hotspot IP.

Once configured, launch the app and the Unreal Engine project to interact with the media art via motion data.
