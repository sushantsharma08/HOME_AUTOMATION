<!-- # Home_Automation
A project for home automation. This is the dummy project of the original, some code changes have been made for the purpose of data security. Developers tryping to copy this project just have to make minor changes to adjust this to there own requirements.

## Description
welcome to this project where I have combined the <b> Electronics </b> of a house with my <b>Computer Science </b> knowledge to automate it. <br/>
I coded the ESP-32 a System On a Chip (SOC) connected to a relay module along with a website that updates the data on a MongoDB server.

## Features

## Tools, Libraries and Frameworks used 
<b>FRONTEND: </b>
1. Vite
2. @tanstack/react-query
3. axios
5. react-router-dom
8. react-hot-toast
9. Tailwindcss as Postcss

<b>BACKEND: </b>
1. bcryptjs
2. cors
3. express
4. mongoose
5. nodemon

<b>HARDWARAE: </b>
1. ESP-32 
2. Relay Modules


## Project Plan
<img src="./assets/workflow.jpg" height="1000px" />


## Make this project your own and automate the home.
### follow these simple steps...

1. **Download the code from this Repository.**

2. **Configuring Backend...** 
    - Install required dependencies <br/><br/>
    Move to the web folder and on the terminal paste the following command to install all required libraries.
<br/><br/>
    ```bash
    npm install
    ```

    - Connect the MongoDB <br/><br/>
    <br/><br/> <img src="./assets/db_config.png" height="400px" /> <br/><br/>
     here add your database connection string in same format and remember the username and password from mongo.

    - Configure the env file
     In the env file place your username, password, port number and the hashing number (recommended 8-12).
     Do the same when deploying by providing these as environment variables.
    
3. **Configuring Frontend...**

    - Putting in origin URL. <br/><br/>
     Move to the components folder under src in Client and open Relay.tsx file. Now under the Origin field paste your URL origin where Backend was deployed.
     example : Home_automation_Backend.com
   <br/><br/> <img src="./assets/url_config.png" height="400px" />

4. **Configure the ESP32 code.**

    - Putting in origin URL.
   <br/><br/> <img src="./assets/espurl_config.png" height="200px" /> <br/><br/>
    Remove this part and paste your URL origin where Backend was deployed. Similar to the previous part.

    - Adding WIFI credentials.
   <br/><br/> <img src="./assets/wifi_config.png" height="200px" /> <br/><br/>
    Add your network details here.

    - Setting up ESP32 and relay. <br/><br/>
    Connect the relay pins to same pins mentioned in the code.


## Final project preview
<img src="./assets/Complete.jpeg" height="800px" /> -->

# Home Automation

A project to automate your home, blending **Electronics** with **Computer Science**. This is a simplified version of the original project, with certain code changes for data security. Developers looking to adapt this can easily make minor modifications to fit their own requirements.

## Description

Welcome to the Home Automation project! This project connects household electronics using an ESP-32 (System On a Chip) and a relay module, controlled via a web interface. The website updates data on a MongoDB server, allowing remote control and automation of various devices.

## Features
- ESP-32 microcontroller integration
- Relay modules for device control
- Full-stack web application for remote access
- MongoDB database for data storage

## Tools, Libraries, and Frameworks

### Frontend:
- **Vite** – Fast build tool
- **@tanstack/react-query** – For data synchronization and caching
- **axios** – Promise-based HTTP client
- **react-router-dom** – Declarative routing
- **react-hot-toast** – Notifications

<!-- **TailwindCSS** for styling -->

### Backend:
- **bcryptjs** – Password hashing
- **cors** – Middleware for Cross-Origin Resource Sharing
- **express** – Web framework for Node.js
- **mongoose** – MongoDB object modeling
- **nodemon** – For automatic server restarting during development

### Hardware:
- **ESP-32** – Microcontroller used for automation
- **Relay Modules** – To control electrical devices

## Project Plan

![Project Workflow](./assets/workflow.jpg)

## How to Make This Project Your Own

### Follow these simple steps to get started:

1. **Download the code** from this repository.

2. **Backend Configuration:**
   - Install the required dependencies:
     ```bash
     npm install
     ```
   - Connect to MongoDB:
     Insert your MongoDB connection string in the appropriate format. Ensure that the username and password are correct.

     ![DB Config](./assets/db_config.png)

   - Set up environment variables:
     - In the `.env` file, add your `DB_USERNAME`, `DB_PASSWORD`, `PORT`, and `HASH_SALT` (recommended: 8-12).
     - If deploying, make sure to provide these values as environment variables.

3. **Frontend Configuration:**
   - Set the origin URL:
     Open the `Relay.tsx` file in the `src/components` folder, and paste your backend's deployment URL under the `Origin` field.
     Example: `https://home_automation_backend.com`

     ![URL Config](./assets/url_config.png)

4. **ESP32 Configuration:**
   - Set the origin URL in the ESP32 code:
     Update the URL field in the ESP32 code to point to your backend's deployment.

     ![ESP32 URL Config](./assets/espurl_config.png)

   - Add your Wi-Fi credentials:
     Insert your Wi-Fi network details to ensure the ESP32 can connect to the internet.

     ![WiFi Config](./assets/wifi_config.png)

   - Set up the ESP32 and Relay:
     Connect the relay pins according to the pin mappings specified in the code.

## Final Project Preview

Here's a snapshot of the final project:

![Final Preview](./assets/Complete.jpeg)
