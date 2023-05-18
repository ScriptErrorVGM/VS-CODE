import greenfoot.*;  // (World, Actor, GreenfootImage, Greenfoot and MouseInfo)

/**
 * Write a description of class Barrier here.
 * 
 * @author (your name) 
 * @version (a version number or a date)
 */
public class Barrier extends Actor
{
    private GreenfootImage image1;
    /**
     * Act - do whatever the Barrier wants to do. This method is called whenever
     * the 'Act' or 'Run' button gets pressed in the environment.
     */
    public void Barrier(){
        GreenfootImage image = new GreenfootImage("Conus.png");

        image.scale(5,5);
        setImage(image);
    }
    
    public void act()
    {
        
    }
    
}
