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
        super(600, 400, 1);
        addObject(new Duke(),200,200);
        addObject(new Code(),50,50);
    }
}
