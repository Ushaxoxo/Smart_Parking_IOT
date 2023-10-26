
import time
import json
import random
from AWSIoTPythonSDK.MQTTLib import AWSIoTMQTTClient

# AWS IoT Core configuration
endpoint = "your-iot-endpoint.amazonaws.com"
root_ca_path = "path-to-root-ca.pem"
private_key_path = "path-to-private-key.pem"
cert_path = "path-to-certificate.pem"
iot_topic = "sensors_data_topic"

# Initialize the AWS IoT MQTT Client
client = AWSIoTMQTTClient("raspberry-pi-sensor-client")
client.configureEndpoint(endpoint, 8883)
client.configureCredentials(root_ca_path, private_key_path, cert_path)

# Connect to AWS IoT
client.connect()
while True:
    # Simulate sensor data (replace with your actual sensor readings)
    sensor_data = {
        "sensor1": random.uniform(0, 100),
        "sensor2": random.uniform(0, 100),
        "sensor3": random.uniform(0, 100)
    }

    # Convert the sensor data to a JSON string
    payload = json.dumps(sensor_data)

    # Publish the sensor data to the AWS IoT Core topic
    client.publish(iot_topic, payload, 1)

    print(f"Published: {payload}")
    time.sleep(5)  # Adjust the frequency of data publishing as needed

# Disconnect from AWS IoT
client.disconnect()

