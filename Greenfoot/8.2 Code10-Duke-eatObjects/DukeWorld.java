import greenfoot.*;  // (World, Actor, GreenfootImage, Greenfoot and MouseInfo)

/**
 * Write a description of class DukeWorld here.
 * 
 * @author (your name) 
 * @version (a version number or a date)
 */
public class DukeWorld extends World
{
    /**
     * Constructor for objects of class DukeWorld.
     * 
     */
    public DukeWorld()
    {    
        // Create a new world and the objects that start the game.
        super(800, 600, 1);
        addObject(new Duke(), 150, 100);
        populate();
    }
    
    public void populate() {
        int[][] array = new int[10][2];
        for (int i = 0; i < array.length; i++) {
                    int x = Greenfoot.getRandomNumber(getWidth());
                    int y = Greenfoot.getRandomNumber(getHeight());
                    array[i][0] = x;
                    array[i][1] = y;
        }
        
        for (int i = 0; i < array.length; i++) { 
                addObject(new Code(),array[i][0],array[i][1]);
        }
    }
}
