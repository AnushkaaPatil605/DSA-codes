import random

# Define board with snakes and ladders
snakes = {99: 7, 70: 55, 52: 29, 25: 2}
ladders = {3: 22, 6: 25, 11: 40, 60: 85}

def roll_dice():
    """Roll the dice and return a number between 1 and 6."""
    return random.randint(1, 6)

def move_player(player_name, position):
    """Move the player based on dice roll and check for snakes/ladders."""
    dice_value = roll_dice()
    print(f"{player_name} rolled: {dice_value}")
    
    new_position = position + dice_value
    
    if new_position > 100:
        print(f"{player_name} rolled too high and stays at {position}.\n")
        return position

    position = new_position

    if position in snakes:
        print(f"Oh no! A snake at {position}. {player_name} goes down to {snakes[position]}")
        position = snakes[position]
    elif position in ladders:
        print(f"Yay! A ladder at {position}. {player_name} climbs up to {ladders[position]}")
        position = ladders[position]

    print(f"{player_name} is now at position {position}\n")
    return position

def play_game():
    print("\n--- Welcome to Snake and Ladder! ---\n")
    num_players = int(input("Enter the number of players: "))
    players = {}

    # Single-player mode with computer
    if num_players == 1:
        player_name = input("Enter your name: ")
        players[player_name] = 1
        players["Computer"] = 1
        print("\nIt's you vs the Computer!\n")
    else:
        # Multi-player mode
        for i in range(num_players):
            name = input(f"Enter player {i + 1} name: ")
            players[name] = 1

    winner = None

    while not winner:
        for player_name in players:
            if player_name == "Computer":
                print("Computer is rolling the dice...")
            else:
                input(f"{player_name}, press Enter to roll the dice...")
            players[player_name] = move_player(player_name, players[player_name])

            if players[player_name] == 100:
                winner = player_name
                break

    print(f"\n🎉 Congratulations {winner}! You won the game!")

# Start the game
play_game()
