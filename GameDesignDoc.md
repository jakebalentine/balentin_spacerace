----
# Space Race

## Game "Things"

The things of Space Race are obstacles/enemies as well as a one powerup! Each enemy is different class of an enemy spaceship that the player must defeat.
 
  1. Drone
    * A purple unit that falls while moving horizontally across the screen.
    * Takes three shot to kill.
    * Worth 25 points.
  2. Praetorian
    * A green unit that falls toward the player's current location.
    * Takes five shots to kill.
    * Worth 75 points.
  3. Deathknight
    * A dark blue unit that stays in center Y of the screen while moving back and forth horizontally.
    * The Deathknight unleashes more Praetorian units toward the player.
    * Ten shots to kill.
    * Worth 300 points.
    
  4. Asteroid
    * Space rock that bounces of the walls horizontally.
    * Two shots to kill.
    * Worth 10 points.
    
  5. Care package
    * Army supplies that double that points you get for a short period of time.
    
## Controls

  1. Click blue and red forcefields
    * Move between forcefields, left and right. This also fires one laser when clicked, but the ship stops if it is already moving in that direction.
  2. Click ship
    * Shoot lasers at enemies.

## Score

  * To score, the player must kill as many enemies as they can. The game goes on forever, so the point of the game is to obtain the high score possible.
  * Killing bigger, badder units gives the user more points.
  * It is difficult to dodge enemies, such as praetorians, but for each enemy dodged, the player will recieve points, as well.

## Lives

  * The player loses a life when it is hit by an enemy. A value for the number of lives is stored in the player class and decremented when a player is hit.
  * When every life is lost, the game restarts and the score is set back to zero.

## Interface

  * The interface will be two horizontal layouts grouped inside a vertical layout.
  * The first horizontal layout will have 3 buttons and to LCD displays:
    * A start button. This starts the game and restarts the application if the game has already started.
    * A pause button. This pauses the game.
    * A score display.
    * A LCD that displays the number of lives the 
    * A quit button. Kills the program.
  * The second horizontal layout will display the scene where the gameplay takes place.
  
![alt text](images/layout.jpg "Layout")
 

