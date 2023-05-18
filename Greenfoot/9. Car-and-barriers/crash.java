import greenfoot.*;  // (World, Actor, GreenfootImage, Greenfoot and MouseInfo)

/**
 * Write a description of class crash here.
 * 
 * @author (your name) 
 * @version (a version number or a date)
 */
public class crash extends Actor
{
    /**
     * Act - do whatever the crash wants to do. This method is called whenever
     * the 'Act' or 'Run' button gets pressed in the environment.
     */
    public void crash()
    {
        initializeImages();
    }
    
    public synchronized static void initializeImages() 
    {
        GreenfootImage baseImage = new GreenfootImage("crash.png");
    }
}

