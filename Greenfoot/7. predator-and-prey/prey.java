import greenfoot.*;  // (World, Actor, GreenfootImage, Greenfoot and MouseInfo)

/**
 * Write a description of class prey here.
 * 
 * @author (your name) 
 * @version (a version number or a date)
 */
public class prey extends Actor
{
    /**
     * Act - do whatever the prey wants to do. This method is called whenever
     * the 'Act' or 'Run' button gets pressed in the environment.
     */
    public void act()
    {   
        int check = Greenfoot.getRandomNumber(10);
        if (isAtEdge()) {
            move(2);
            turn(45);
        } else {
            move(5);
            if (check/2 == 1){
                randomTurn();
            }
        }
    }
    
        public void randomTurn()
    {
        if (Greenfoot.getRandomNumber(100) > 90) 
        {
            turn(Greenfoot.getRandomNumber(90)-45);
        }
    }
}
