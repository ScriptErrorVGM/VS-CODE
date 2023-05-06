import greenfoot.*;  // (World, Actor, GreenfootImage, Greenfoot and MouseInfo)

/**
 * Write a description of class Duke here.
 * 
 * @author (your name) 
 * @version (a version number or a date)
 */
public class Duke extends Animal
{
    /**
     * Act - do whatever the Duke wants to do. This method is called whenever
     * the 'Act' or 'Run' button gets pressed in the environment.
     */
    public void act() 
    {
        if (Greenfoot.getRandomNumber(100) < 10)
        {   
            int[] nums = new int[] { -30, 30 };
            turn(nums[Greenfoot.getRandomNumber(nums.length)]);
        } else if (isAtEdge()){
            turn(180);
        }
        move(2);
    } 
}