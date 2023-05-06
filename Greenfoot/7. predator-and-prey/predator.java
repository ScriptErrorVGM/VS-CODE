import greenfoot.*;  // (World, Actor, GreenfootImage, Greenfoot and MouseInfo)

/**
 * Write a description of class predator here.
 * 
 * @author (your name) 
 * @version (a version number or a date)
 */
public class predator extends Actor
{
    /**
     * Act - do whatever the predator wants to do. This method is called whenever
     * the 'Act' or 'Run' button gets pressed in the environment.
     */
    public void act()
    {   
        if (foundPrey()){
            eatPrey();
        } else if (!isAtEdge()) {
            move();
            randomTurn();
        } else if (isAtEdge()){
            turn(17);
            move();
        }

    }
    
    /**
     * Move one step forward.
     */
    public void move()
    {
        move(3);
    }

    /**
     * Turn left by 90 degrees.
     */
    public void turnLeft()
    {   
        turn(90);
    }
    
    public void randomTurn()
    {
        if (Greenfoot.getRandomNumber(100) > 90) 
        {
            turn(Greenfoot.getRandomNumber(90)-45);
        }
    }
    
    public boolean foundPrey()
    {
        Actor leaf = getOneObjectAtOffset(0, 0, prey.class);
        return leaf != null;
    }
    
    public void eatPrey()
    {
        Actor prey = getOneObjectAtOffset(0, 0, prey.class);
        if (prey != null) {
            // eat the leaf...
            getWorld().removeObject(prey);
        }
    }
}
