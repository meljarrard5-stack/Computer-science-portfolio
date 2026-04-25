# ModuleSixMilestone.py
# Author: Melanie Jarrard
# Description:
#   Simplified text-based room navigation game for IT 140 Module Six Milestone.
#   The player can move between connected rooms or type "exit" to end the game.


# A dictionary for the simplified dragon text game
# The dictionary links each room to its possible exits.
rooms = {
    'Great Hall': {'South': 'Bedroom'},
    'Bedroom': {'North': 'Great Hall', 'East': 'Cellar'},
    'Cellar': {'West': 'Bedroom'}
}


def show_current_location(current_room):
    """
    Show the player's current room and available exits.
    """
    print("\nYou are currently in the:", current_room)

    exits = rooms.get(current_room, {})

    if exits:
        print("You can move in the following directions:")
        for direction in exits:
            print(f"  - {direction}")
    else:
        print("There are no exits from this room.")


def parse_direction(user_command):
    """
    Convert the user input into a direction (North, South, East, or West).
    Accepts formats like:
      - "north"
      - "Go south"
      - "WEST"
    Returns:
      The direction title-cased if valid, or None if invalid.
    """
    user_command = user_command.strip()

    if not user_command:
        return None

    parts = user_command.split()
    allowed = {"North", "South", "East", "West"}

    # If user typed a single word like "north"
    if len(parts) == 1:
        direction = parts[0].title()
        if direction in allowed:
            return direction
        return None

    # If user typed something like "go north"
    if parts[0].lower() == "go" and len(parts) >= 2:
        direction = parts[1].title()
        if direction in allowed:
            return direction
        return None

    return None


def main():
    """
    Main gameplay loop for the simplified text adventure.
    """
    current_room = "Great Hall"      # Start room
    EXIT_ROOM_NAME = "exit"          # Used to control loop termination

    # The loop continues until the player enters "exit"
    while current_room != EXIT_ROOM_NAME:

        # Show room and possible exits
        show_current_location(current_room)

        # Prompt for input
        print('\nEnter a direction (North, South, East, West)')
        user_command = input('Or type "exit" to leave the game: ')

        # Handle exit command
        if user_command.lower().strip() == "exit":
            print("\nYou have chosen to exit the game. Goodbye!")
            current_room = EXIT_ROOM_NAME   # Loop ends naturally
            continue

        # Try to interpret the movement command
        direction = parse_direction(user_command)

        # Invalid command
        if direction is None:
            print('\nInvalid command. Please enter a valid direction such as "North" or "go South",')
            print('or type "exit" to end the game.')
            continue

        # Valid format, now check if movement is allowed
        exits = rooms.get(current_room, {})

        if direction in exits:
            new_room = exits[direction]
            print(f"\nYou move {direction} to the {new_room}.")
            current_room = new_room
        else:
            print(f'\nYou cannot go {direction} from the {current_room}. Try a different direction.')

    # Loop has ended
    print("\nGame over. Thanks for playing!")


# Run main only if executed directly
if __name__ == "__main__":
    main()
