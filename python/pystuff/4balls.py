import pygame
import sys
import random

# Initialize Pygame
pygame.init()

# Set up the display
width, height = 600, 400
screen = pygame.display.set_mode((width, height))
pygame.display.set_caption("Bouncing Balls!")

# Create a clock to control framerate
clock = pygame.time.Clock()

# --- Regular Balls Setup ---
balls = []
for _ in range(4):  # 4 regular balls
    ball = {
        "x": random.randint(50, width - 50),
        "y": random.randint(50, height - 50),
        "radius": 30,
        "x_speed": random.choice([-4, 4]),
        "y_speed": random.choice([-4, 4]),
        "color": (
            random.randint(50, 255),
            random.randint(50, 255),
            random.randint(50, 255)
        )
    }
    balls.append(ball)

# --- Special Green Ball ---
power_ball = {
    "x": width // 2,
    "y": height // 2,
    "radius": 25,
    "x_speed": 3,
    "y_speed": 3,
    "color": (0, 255, 0),
    "growth_rate": 0.05,
    "speed_boost": 0.01
}

# Main Game Loop
running = True
while running:
    for event in pygame.event.get():
        if event.type == pygame.QUIT:
            running = False

    # --- Update Regular Balls ---
    for ball in balls:
        ball["x"] += ball["x_speed"]
        ball["y"] += ball["y_speed"]

        # Bounce off walls
        if (ball["x"] + ball["radius"] >= width) or (ball["x"] - ball["radius"] <= 0):
            ball["x_speed"] = -ball["x_speed"]
        if (ball["y"] + ball["radius"] >= height) or (ball["y"] - ball["radius"] <= 0):
            ball["y_speed"] = -ball["y_speed"]

    # --- Update Green Power Ball ---
    power_ball["x"] += power_ball["x_speed"]
    power_ball["y"] += power_ball["y_speed"]

    # Bounce off walls
    if (power_ball["x"] + power_ball["radius"] >= width) or (power_ball["x"] - power_ball["radius"] <= 0):
        power_ball["x_speed"] = -power_ball["x_speed"]
    if (power_ball["y"] + power_ball["radius"] >= height) or (power_ball["y"] - power_ball["radius"] <= 0):
        power_ball["y_speed"] = -power_ball["y_speed"]

    # Grow and speed up over time
    power_ball["radius"] += power_ball["growth_rate"]
    if power_ball["x_speed"] > 0:
        power_ball["x_speed"] += power_ball["speed_boost"]
    else:
        power_ball["x_speed"] -= power_ball["speed_boost"]
    if power_ball["y_speed"] > 0:
        power_ball["y_speed"] += power_ball["speed_boost"]
    else:
        power_ball["y_speed"] -= power_ball["speed_boost"]

    # --- DRAWING ---
    screen.fill((0, 0, 0))
    for ball in balls:
        pygame.draw.circle(screen, ball["color"], (int(ball["x"]), int(ball["y"])), int(ball["radius"]))
    pygame.draw.circle(screen, power_ball["color"], (int(power_ball["x"]), int(power_ball["y"])), int(power_ball["radius"]))

    pygame.display.flip()
    clock.tick(60)

# Quit Pygame
pygame.quit()
sys.exit()
