import pandas as pd
import matplotlib.pyplot as plt
import os

# Load the re-uploaded file
df = pd.read_csv("2105142.csv")

# Sort by graph name
df = df.sort_values("Name").reset_index(drop=True)

# Create output directory
output_dir = "data/max_cut_plots"
os.makedirs(output_dir, exist_ok=True)

# Generate 6 plots, each with 10 graphs (last with 4 if total is 54)
num_graphs = len(df)
graphs_per_plot = 10
num_plots = (num_graphs + graphs_per_plot - 1) // graphs_per_plot

generated_files = []

for i in range(num_plots):
    start_idx = i * graphs_per_plot
    end_idx = min(start_idx + graphs_per_plot, num_graphs)
    sample = df.iloc[start_idx:end_idx]
    x_labels = sample["Name"]
    index = range(len(sample))

    plt.figure(figsize=(12, 6))
    bar_width = 0.15

    plt.bar([j - 2 * bar_width for j in index], sample["Randomized"], width=bar_width, label='Randomized')
    plt.bar([j - bar_width for j in index], sample["Greedy"], width=bar_width, label='Greedy')
    plt.bar(index, sample["SemiGreedy"], width=bar_width, label='Semi-Greedy')
    plt.bar([j + bar_width for j in index], sample["LocalSearch"], width=bar_width, label='Local Search')
    plt.bar([j + 2 * bar_width for j in index], sample["GRASP"], width=bar_width, label='GRASP')

    plt.xlabel("Graph Name")
    plt.ylabel("Max-Cut Value")
    plt.title(f"Max Cut Comparison: Graphs {start_idx + 1} to {end_idx}")
    plt.xticks(index, x_labels, rotation=45)
    plt.legend()
    plt.tight_layout()

    filename = f"max_cut_comparison_{i+1}.png"
    filepath = os.path.join(output_dir, filename)
    plt.savefig(filepath)
    generated_files.append(filepath)
    plt.close()

generated_files
