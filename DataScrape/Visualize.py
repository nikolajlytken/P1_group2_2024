import osmnx as ox
import networkx as nx
import matplotlib.pyplot as plt

# Define the place of interest
place_name = "Copenhagen, Denmark"

# Retrieve the railway network
G = ox.graph_from_place(place_name, network_type='all', custom_filter='["railway"~"station|rail"]')

# Plot the graph
fig, ax = ox.plot_graph(G, node_size=10, node_color='red', edge_color='black', edge_linewidth=1.0)