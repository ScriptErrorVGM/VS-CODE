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
    private int codeConsumed;

    public Duke()
    {   
        codeConsumed = 0;
    }
    public void act() 
    {
        if (Greenfoot.getRandomNumber(100) < 10)
        {
            int[] nums = new int[] { -30, 30 };
            turn(nums[Greenfoot.getRandomNumber(nums.length)]);
        } else if (Greenfoot.getRandomNumber(100) < 10)
        {
            turn(5);
        } else if (isAtEdge()){
            turn(180);
        }
        if(getCodeConsumed() > 10){
            move(9);
        } else {
            move(2);
        }
        lookForCode();
    } 
    /**
     * Look for Code. If Duke finds code, he eats it. 
     */
    public void lookForCode()
    {
        if(canSee(Code.class))
        {
            eat(Code.class);
            codeConsumed = codeConsumed + 1;
        }
        
    }
    
    public int getCodeConsumed()
    {
        return codeConsumed;
    }
}

