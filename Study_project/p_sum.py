import tkinter as tk
import matplotlib.pyplot as plt
import numpy as np

def bezier_curve(points, t):
    # Convert points to NumPy arrays
    p0, p1, p2, p3 = np.array(points[0]), np.array(points[1]), np.array(points[2]), np.array(points[3])
    
    # Calculation of the point on the cubic Bezier curve
    u = 1 - t
    tt = t * t
    uu = u * u
    uuu = uu * u
    ttt = tt * t

    p = uuu * p0 + 3 * uu * t * p1 + 3 * u * tt * p2 + ttt * p3
    return p

def plot_bezier_curve(points):
    # Drawing the cubic Bezier curve
    t = np.linspace(0, 1, 100)
    x_points = []
    y_points = []
    for i in t:
        p = bezier_curve(points, i)
        x_points.append(p[0])
        y_points.append(p[1])

    plt.plot(x_points, y_points, 'b-', label='Bezier Curve')
    plt.scatter([p[0] for p in points], [p[1] for p in points], c='r', label='Control Points')
    plt.legend()
    plt.xlabel('X')
    plt.ylabel('Y')
    plt.title('Bezier Curve of Order 3')
    plt.grid(True)
    plt.show()

def on_button_click():
    # Handler for the "Plot" button click
    x1 = float(entry_x1.get())
    y1 = float(entry_y1.get())
    x2 = float(entry_x2.get())
    y2 = float(entry_y2.get())
    x3 = float(entry_x3.get())
    y3 = float(entry_y3.get())
    x4 = float(entry_x4.get())
    y4 = float(entry_y4.get())

    control_points = [(x1, y1), (x2, y2), (x3, y3), (x4, y4)]
    plot_bezier_curve(control_points)

# Create the GUI window
window = tk.Tk()
window.title("Bezier Curve")

# Create labels and entry fields for inputting control points
label_x1 = tk.Label(window, text="X1:")
label_x1.pack()
entry_x1 = tk.Entry(window)
entry_x1.pack()

label_y1 = tk.Label(window, text="Y1:")
label_y1.pack()
entry_y1 = tk.Entry(window)
entry_y1.pack()

label_x2 = tk.Label(window, text="X2:")
label_x2.pack()
entry_x2 = tk.Entry(window)
entry_x2.pack()

label_y2 = tk.Label(window, text="Y2:")
label_y2.pack()
entry_y2 = tk.Entry(window)
entry_y2.pack()

label_x3 = tk.Label(window, text="X3:")
label_x3.pack()
entry_x3 = tk.Entry(window)
entry_x3.pack()

label_y3 = tk.Label(window, text="Y3:")
label_y3.pack()
entry_y3 = tk.Entry(window)
entry_y3.pack()

label_x4 = tk.Label(window, text="X4:")
label_x4.pack()
entry_x4 = tk.Entry(window)
entry_x4.pack()

label_y4 = tk.Label(window, text="Y4:")
label_y4.pack()
entry_y4 = tk.Entry(window)
entry_y4.pack()

# Create a button for plotting
button = tk.Button(window, text="Plot", command=on_button_click)
button.pack()

# Run the main event loop
window.mainloop()
