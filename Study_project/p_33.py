import tkinter as tk
from tkinter import ttk
from matplotlib.figure import Figure
from matplotlib.backends.backend_tkagg import FigureCanvasTkAgg
from matplotlib.animation import FuncAnimation
import matplotlib.pyplot as plt
import math


def draw_bezier_curve(degree, control_points, ax):
    t = [i / 100 for i in range(101)]
    n = degree + 1
    curve_points = []

    for t_val in t:
        x = 0
        y = 0

        for i in range(n):
            coeff = math.comb(n - 1, i) * (1 - t_val) ** (n - 1 - i) * t_val ** i
            x += control_points[i][0] * coeff
            y += control_points[i][1] * coeff

        curve_points.append([x, y])

    curve_points = list(map(list, zip(*curve_points)))
    ax.plot(curve_points[0], curve_points[1], 'b')

    return curve_points


# Create a tkinter window
root = tk.Tk()
root.title("Bezier Curve Animation")
root.geometry("800x600")

# Create a matplotlib figure inside the tkinter window
fig = Figure(figsize=(6, 4), dpi=100)
ax = fig.add_subplot(111)
ax.set_aspect('equal')
ax.grid(True)
ax.set_xlabel('X')
ax.set_ylabel('Y')

canvas = FigureCanvasTkAgg(fig, master=root)
canvas.draw()
canvas.get_tk_widget().pack(side=tk.TOP, fill=tk.BOTH, expand=True)

# Create control point entry widgets
control_point_entries = []
for i in range(4):
    label = ttk.Label(root, text=f"Control Point {i+1}: (x, y)")
    label.pack()
    entry = ttk.Entry(root)
    entry.pack()
    entry.insert(0, "0.0, 0.0")
    control_point_entries.append(entry)

# Initialize square patch
square_size = 0.05  # Square size relative to the graph size
square = plt.Rectangle((0, 0), square_size, square_size, facecolor='blue')
square_patch = ax.add_patch(square)


def update_graph(frame):
    ax.clear()
    ax.set_aspect('equal')
    ax.grid(True)
    ax.set_xlabel('X')
    ax.set_ylabel('Y')

    # Read control points from entry widgets
    control_points = []
    for entry in control_point_entries:
        value = entry.get()
        try:
            x, y = map(float, value.split(','))
        except ValueError:
            x, y = 0.0, 0.0
        control_points.append([x, y])

    curve_points = draw_bezier_curve(3, control_points, ax)

    # Get the x and y coordinates of the curve points
    x_coords = curve_points[0]
    y_coords = curve_points[1]

    # Find the minimum and maximum values of the x and y coordinates
    x_min = min(x_coords)
    x_max = max(x_coords)
    y_min = min(y_coords)
    y_max = max(y_coords)

    # Calculate the range of the x and y coordinates
    x_range = x_max - x_min
    y_range = y_max - y_min

    # Set the x and y limits based on the calculated ranges
    x_padding = x_range * 0.1
    y_padding = y_range * 0.1

    ax.set_xlim(x_min - x_padding, x_max + x_padding)
    ax.set_ylim(y_min - y_padding, y_max + y_padding)

    # Calculate the position of the square based on the frame number
    t = frame / frames_total
    square_x = 0
    square_y = 0

    for i, point in enumerate(control_points):
        coeff = math.comb(3, i) * (1 - t) ** (3 - 1 - i) * t ** i
        square_x += point[0] * coeff
        square_y += point[1] * coeff

    # Scale the square size relative to the graph size
    graph_width = ax.get_xlim()[1] - ax.get_xlim()[0]
    graph_height = ax.get_ylim()[1] - ax.get_ylim()[0]
    square_size_scaled = square_size * min(graph_width, graph_height)

    # Update the position and size of the square
    square_patch.set_xy((square_x - square_size_scaled / 2, square_y - square_size_scaled / 2))
    square_patch.set_width(square_size_scaled)
    square_patch.set_height(square_size_scaled)

    # Redraw the canvas to update the plot
    canvas.draw()

    return square_patch,


# Animation settings
frames_total = 100  # Total number of frames
animation = FuncAnimation(fig, update_graph, frames=frames_total, interval=50, repeat=True, blit=True)

# Start the tkinter event loop
tk.mainloop()
