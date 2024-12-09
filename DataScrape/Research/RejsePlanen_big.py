import requests
import json

# Define the base URL and endpoint
base_url = "https://www.rejseplanen.dk/api/"
endpoint = "lineInfo"
lines = ["69","75","76"]

for line in lines: 
    # Define the parameters (replace YOUR_ACCESS_ID with your actual API key)
    params = {
        "accessId": "6b2d0ad1-44e1-49df-a746-82580093194c",
        "format": "json",
        "lineId": f"065_280_00_{line}",
        "date":"2024-11-22"  # or "xml" depending on the desired response format
        #"lineId": "006_000022_A"  # Example line ID (adjust based on your needs)
    }
    # Construct the full URL
    url = f"{base_url}{endpoint}"

    # Make the GET request
    response = requests.get(url, params=params)

    # Check the response status
    if response.status_code == 200:
        try:
            # Parse the JSON response
            data = response.json()  # Use response.text if the response is XML
            # Write the data to a file
            with open(f'response_data_{endpoint}_{line}.json', 'w') as file:
                json.dump(data, file, indent=4)
            
            print("Data written to response_data.json")
        except requests.exceptions.JSONDecodeError:
            print("Response content is not valid JSON")
    else:
        print(f"Error: {response.status_code}")
        print(response.text)