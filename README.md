# particle-weather-station

Temperature and humidity logger using a Particle Photon board and a DHT11 sensor.

Reference: [Make a Cloud Data Logger With the Particle Photon](https://www.openhomeautomation.net/cloud-data-logger-particle-photon/).

## Supplies

* [Particle Photon](https://store.particle.io/)
* [DHT11 sensor](https://www.adafruit.com/product/386) (includes a resistor)
* Breadboard
* Jumper wires

## Hardware configuration

Go through the [Particle Photon Getting Started Guide](https://docs.particle.io/guide/getting-started/intro/photon/) to get your Photon up and running. Then, wire up the board. Here's a picture of the circuit:

![Circuit](https://raw.githubusercontent.com/drejkim/particle-weather-station/master/img/circuit.jpg)

First, let's wire up the Photon:

* Place the Photon on the left side of the breadboard.
* Connect a jumper wire from the 3V3 pin to the power line of the breadboard.
* Connect a jumper wire from the GND pin to the ground line of the breadboard.

Now, let's wire up the DHT11 sensor:

* Add the DHT11 sensor to the right side of the breadboard, with the perforated side facing you. Note that there are 4 pins, from left to right: VCC, Data out, Not connected, and GND.
* Connect VCC to one of the breadboard's power pins.
* Connect GND to one of the breadboard's ground pins.
* Connect the Data out pin to D5 of the Photon.
* Connect the resistor between the VCC and data pins.

## Using the Particle Dev IDE

* Download the [Particle Dev IDE](https://www.particle.io/dev) and follow the [instructions](https://docs.particle.io/guide/tools-and-features/dev/) on how to log into your account and select your device.
* Open `ino/dht11.ino` in the IDE.

## Viewing the data with Ubidots

You can visualize the data in realtime using [Ubidots](http://ubidots.com/), a cloud service for visualizing sensor data.

Here's a screenshot of my Ubidots dashboard:

![Ubidots](https://raw.githubusercontent.com/drejkim/particle-weather-station/master/img/ubidots.png)

To create your own dashboard:

* Sign up for an [Ubidots](http://ubidots.com/) account
* Modify `UBIDOTS_TOKEN` in `ino/dht11.ino`:
  * You can find your token on Ubidots by clicking on your username, selecting **API Credentials**, then copying the default token
* Send the code to the board
  * Select the **Compile** button. If it's compiled successfully, the status bar on the bottom should say, "Success!"
  * Send the code to the board by selecting the **Flash** button. Again, if it's successful, the status bar should say, "Success!"
* In Ubidots, go to the **Dashboard** section
  * Click on the orange **Add** button and add a chart for the temperature variable: **Chart** -> **Line chart** -> **Add variable** -> **Particle Weather Station** -> **temperature** -> **Add variable** -> **Finish!**
  * Repeat the above for **humidity**
  * You should now have two line charts showing the temperature and humidity data!
