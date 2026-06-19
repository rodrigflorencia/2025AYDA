import numpy as np
import matplotlib.pyplot as plt

class Point:
    def __init__(self, x=0, y=0):
        self.x = x
        self.y = y

    def get_distance(self, other):
        return np.sqrt((self.x - other.x)**2 + (self.y - other.y)**2)

def triangle_cost(p1, p2, p3):
    return p1.get_distance(p2) + p2.get_distance(p3) + p3.get_distance(p1)

def min_triangulation(points):
    n = len(points)
    dp = [[0 if j < i + 2 else float('inf') for j in range(n)] for i in range(n)]
    split = [[-1] * n for _ in range(n)]

    for gap in range(2, n):
        for i in range(n - gap):
            j = i + gap
            for k in range(i + 1, j):
                cost = dp[i][k] + dp[k][j] + triangle_cost(points[i], points[k], points[j])
                if cost < dp[i][j]:
                    dp[i][j] = cost
                    split[i][j] = k

    return dp, split

def get_triangulation(split, i, j, triangulation):
    if j <= i + 1:
        return
    k = split[i][j]
    triangulation.append((i, j))
    get_triangulation(split, i, k, triangulation)
    get_triangulation(split, k, j, triangulation)

def draw_polygon_with_triangulation(points, title, triangulation):
    points = np.array([(p.x, p.y) for p in points])
    fig, ax = plt.subplots()
    polygon = plt.Polygon(points, closed=True, fill=None, edgecolor='r')
    ax.add_patch(polygon)

    for i, point in enumerate(points):
        ax.text(point[0], point[1], f'({point[0]}, {point[1]})', fontsize=12, ha='right')

    for (i, j) in triangulation:
        ax.plot([points[i][0], points[j][0]], [points[i][1], points[j][1]], 'k--')

    ax.set_title(title)
    ax.set_xlim(min(points[:, 0]) - 1, max(points[:, 0]) + 1)
    ax.set_ylim(min(points[:, 1]) - 1, max(points[:, 1]) + 1)
    plt.grid(False)
    plt.gca().set_aspect('equal', adjustable='box')
    plt.show()

# Ejemplo de uso
def main():
    square_points = [Point(0, 0), Point(0, 10), Point(10, 10), Point(10, 0)]
    pentagon_points = [Point(0, 0), Point(1, 2), Point(3, 3), Point(5, 2), Point(4, 0)]
    hexagon_points = [Point(0, 0), Point(2, 1), Point(4, 1), Point(6, 0), Point(4, -2), Point(2, -2)]
    octagon_points = [Point(0, 0), Point(2, 1), Point(4, 2), Point(6, 1), Point(8, 0), Point(6, -2), Point(4, -3), Point(2, -2)]
    heptagono_points = [Point(0,10),Point(0,20),Point(8,26),Point(15,26),Point(27,21),Point(22,12), Point(10,0)]
    polygons = [
        (square_points, "Cuadrado"),
        (pentagon_points, "Pentágono"),
        (hexagon_points, "Hexágono"),
        (octagon_points, "Octágono"),
        (heptagono_points, "Heptágono")
    ]

    for points, title in polygons:
        dp, split = min_triangulation(points)
        triangulation = []
        get_triangulation(split, 0, len(points) - 1, triangulation)
        draw_polygon_with_triangulation(points, title, triangulation)

if __name__ == "__main__":
    main()
