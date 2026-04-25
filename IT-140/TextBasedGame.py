# TextBasedGame.py
# Author: Melanie Jarrard
# Secrets of the Moonshadow Forest - Text Adventure Game
# IT 140 Project Two

def show_instruction():
    """
    Display the main menu and instructions for the game
    """
    print("=======================================")
    print("      Secrets of the Moonshadow Forest ")
    print("=======================================")
    print("You woke up in an enchanted forest with no idea how you got there.")
    print("Long ago, forest relics were used to protect this place.")
    print("Now the Forest Guardian has been twisted into a monster in the Beast's Lair.")
    print("Your goal is to collect ALL of the magical relics")
    print("before you enter the Beast's Lair.")
    print()
    print("Move commands: go North, go South, go East, go West")
    print("Add to inventory: get <item name>")
    print("---------------------------------------")


def show_status(current_room, inventory, rooms):
    """
    Show the player's current status:
    -current room
    -current inventory
    -item in the room (if any)
    """
    print("\n---------------------------------------")
    print("You are in the:", current_room)
    print("Inventory:", inventory)

    room_info = rooms[current_room]
    item_in_room = room_info.get("item")

    if item_in_room is not None:
        print("You see a:", item_in_room)
    else:
        print("There is no item in this area.")

    print("---------------------------------------")


def show_instructions():
    pass


def main():
    """
    Main function that controls the gameplay loop
    """
    rooms = {
        "Forest Entrance": {"North": "Whispering Grove"},

        "Whispering Grove": {
            "South": "Forest Entrance",
            "East": "Crystal Pond",
            "North": "Ancient Oak Hollow",
            "West": "Shimmering Marsh",
            "item": "Silver Whistle"
        },

        "Crystal Pond": {
            "West": "Whispering Grove",
            "item": "Moonstone Lantern"
        },

        "Ancient Oak Hollow": {
            "South": "Whispering Grove",
            "North": "Thorn Maze",
            "West": "Moonlit Ruins",
            "East": "Echo Cavern",
            "item": "Enchanted Vines"
        },

        "Moonlit Ruins": {
            "East": "Ancient Oak Hollow",
            "item": "Crystal Feather"
        },

        "Thorn Maze": {
            "South": "Ancient Oak Hollow",
            "North": "Skybridge Cliff",
            "East": "Umbral Crossing",
            "item": "Forest Charm"
        },

        "Skybridge Cliff": {
            "South": "Thorn Maze",
            "item": "Mirror of Truth"
        },

        "Echo Cavern": {
            "West": "Ancient Oak Hollow",
            "South": "Shimmering Marsh",
            "item": "Spirit Chime"
        },

        "Shimmering Marsh": {
            "North": "Echo Cavern",
            "West": "Whispering Grove",
            "item": "Glimmer Reed"
        },

        "Umbral Crossing": {
            "West": "Thorn Maze",
            "North": "Beast's Lair",
            "item": "Shadow Petal"
        },

        "Beast's Lair": {
            "South": "Umbral Crossing"
        }
    }

    # Count items needed to win
    total_items = 0
    for room_data in rooms.values():
        if "item" in room_data:
            total_items += 1

    # Starting state
    current_room = "Forest Entrance"
    inventory = []

    # Show instructions at game start
    show_instructions()

    # ===========================
    #        GAMEPLAY LOOP
    # ===========================
    while True:

        show_status(current_room, inventory, rooms)

        user_input = input("Enter your move: ").strip()

        # Empty input protection
        if user_input == "":
            print("Please enter a command.")
            continue

        parts = user_input.split(" ", 1)
        command = parts[0].lower()

        # ===========================
        #         MOVE COMMAND
        # ===========================
        if command == "go":
            if len(parts) < 2:
                print("Go where? Try: go North, go South, go East, go West.")
                continue

            direction = parts[1].title()

            if direction in rooms[current_room]:
                current_room = rooms[current_room][direction]
                print("You move", direction, "into the", current_room + ".")
            else:
                print("You can't go in that way from here.")
                continue

        # ===========================
        #        GET ITEM COMMAND
        # ===========================
        elif command == "get":
            if len(parts) < 2:
                print("get what? Example: get Silver Whistle")
                continue

            requested_item = parts[1].strip()
            room_item = rooms[current_room].get("item")

            if room_item is None:
                print("There is no item in this room.")
                continue

            if requested_item.lower() != room_item.lower():
                print("That item is not here.")
                continue

            if room_item in inventory:
                print("you already picked up that item.")
            else:
                inventory.append(room_item)
                print(room_item, "has been added to your inventory.")
                del rooms[current_room]["item"]

        # ===========================
        #     INVALID COMMAND
        # ===========================
        else:
            print("Invalid command.")
            print("Try: go North, go South, go East, go West, or get <item name>.")
            continue

        # ============================================
        #        WIN / LOSE CONDITIONS
        # ============================================
        if current_room == "Beast's Lair":
            if len(inventory) == total_items:
                print("\nYou enter the Beast's Lair unprepared.")
                print("The relics glow brightly, surrounding the correupted Guardian.")
                print("The curse shatters, restoring the Guardian to their true form!")
                print("Congratulations! You saved the Moonshadow Forest!")
                print("Thanks for playing Secrets of the Moonshadow Forest.")
                break
            else:
                print("\nYou enter the Beast's Lair unprepared.")
                print("The corrupted Forest Guardian awakens and overwhelms you.")
                print("NOM NOM...GAME OVER!")
                print("Thanks for playing Secrets of the Moonshadow Forest.")
                break

# Run the game
if __name__ == "__main__":
    main()
