import greenfoot.*;  // (World, Actor, GreenfootImage, Greenfoot and MouseInfo)

/**
 * Write a description of class Car here.
 * 
 * @author (your name) 
 * @version (a version number or a date)
 */
public class Car extends Actor
{
    int speed = 0;
    final int MAX_SPEED = 10;
    final int MIN_SPEED = -10;
    final int DELAY = 20;
    /**
     * Act - do whatever the Car wants to do. This method is called whenever
     * the 'Act' or 'Run' button gets pressed in the environment.
     */
    public void act()
    {
        move(speed);
        checkKeypress();
        if (isTouching(Barrier.class)) move(-speed);
    }
    
    public void checkKeypress()
    {   
        if (Greenfoot.isKeyDown("space")) 
        {
            speed = 0;
        }
        if (Greenfoot.isKeyDown("up") && speed < MAX_SPEED * DELAY)
        {
            move(speed++);
        }
        if (Greenfoot.isKeyDown("down") && speed > MIN_SPEED * DELAY)
        {
            move(speed--);
        }
        if (Greenfoot.isKeyDown("left")) 
        {
            turn(-2);
        }
        if (Greenfoot.isKeyDown("right")) 
        {
            turn(2);
        }
    }
    
    public void setLocation(int x, int y)
    {
        int oldX = getX();
        int oldY = getY();
        super.setLocation(x, y);
        if(!getIntersectingObjects(Barrier.class).isEmpty())
        {
            super.setLocation(oldX, oldY);
        }
    }
}
