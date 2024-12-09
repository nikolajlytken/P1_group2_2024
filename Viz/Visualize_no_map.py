# import osmnx as ox
# import networkx as nx
# import matplotlib.pyplot as plt

# # Define the place of interest
# place_name = "Copenhagen, Denmark"

# # Retrieve the railway network
# G = ox.graph_from_place(place_name, network_type='all', custom_filter='["railway"~"station|rail"]')

# # Plot the graph
# fig, ax = ox.plot_graph(G, node_size=10, node_color='red', edge_color='black', edge_linewidth=1.0)

import pandas as pd 
import matplotlib.pyplot as plt



train_stations = pd.read_csv('dataset.csv')

print(train_stations)

# plt.figure(figsize=(8,6))  # optional: sets the figure size
# plt.scatter(train_stations, latitudes, marker='o', color='blue', edgecolor='black')
# plt.title('Plot of Coordinates Without a Map')
# plt.xlabel('Longitude')
# plt.ylabel('Latitude')
# plt.grid(True)  # optional: add a grid for reference
# plt.show()