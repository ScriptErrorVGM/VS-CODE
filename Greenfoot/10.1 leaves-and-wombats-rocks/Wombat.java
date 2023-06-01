import greenfoot.*;  // (World, Actor, GreenfootImage, and Greenfoot)

/**
 * Wombat. A Wombat moves forward until it hits the edge of the world, at
 * which point it turns left. If a wombat finds a leaf, it eats it.
 * 
 * @author Michael Kölling
 * @version 2.0
 */
public class Wombat extends Actor
{
    private int leavesEaten;
    int rotationalSpeed = 1;
    int radius = 2; // adjust as needed
    private int angle = 0;
    public Wombat()
    {   
        leavesEaten = 0;
    }

    /**
     * Do whatever the wombat likes to to just now.
     */
    public void act()
    {   
        checkEnd();
        checkRocks();
        if (foundLeaf()) {
            eatLeaf();
        }
        else if (canMove()) {
            move();
        }
        else if (isAtEdge()){
            turnLeft();
        }
    }
    
    public void checkRocks(){
        //Rock rock = (Rock)getOneIntersectingObject(Rock.class);
        //if(!getIntersectingObjects(Rock.class).isEmpty()){
        if(isTouching(Rock.class)){
            turn(-90);
            move(1);
            //Greenfoot.delay(2);
            turn(90);
            move(1);
            //Greenfoot.delay(2);
            turn(90);
            move(1);
            //Greenfoot.delay(2);
            turn(-90);
            move(1);
            /*if (Greenfoot.getRandomNumber(100) < 50)
            {   
                turn(-7);
                move(1);
                turn(7);
                
                int[] nums = new int[] { -90, 90};
                turn(nums[Greenfoot.getRandomNumber(nums.length)]);
                move(1);
                turn(-nums[Greenfoot.getRandomNumber(nums.length)]);
                move(1);
                turn(-nums[Greenfoot.getRandomNumber(nums.length)]);
                
                
            }*/
            
            //turn(-90);
            //move();// adjust 'orbital distance' value as needed
            //turn(90);
            //move(1);
            //turn(90);
            //turn(90);
        }
    }
    
    public void checkEnd(){
        if (getLeavesEaten() == 5){
            Greenfoot.stop();
        }
    }
    
    /**
     * Move one step forward.
     */
    public void move()
    {
        move(1);
    }
    
    /**
     * Turn left by 90 degrees.
     */
    public void turnLeft()
    {   
        if (Greenfoot.getRandomNumber(100) < 10)
        {   
            //turn(90);
            int[] nums = new int[] { -90, 90};
            turn(nums[Greenfoot.getRandomNumber(nums.length)]);
        }
    }
       
    /**
     * Check whether there is a leaf in the same cell as we are.
     * Return true, if there is, false otherwise.
     */
    public boolean foundLeaf()
    {
        Actor leaf = getOneObjectAtOffset(0, 0, Leaf.class);
        return leaf != null;
    }
    
    /**
     * Eat a leaf (if there is one in our cell).
     */
    public void eatLeaf()
    {
        Actor leaf = getOneObjectAtOffset(0, 0, Leaf.class);
        if (leaf != null) {
            // eat the leaf...
            getWorld().removeObject(leaf);
            leavesEaten = leavesEaten + 1; 
        }
    }
    
    /**
     * Set the direction we're facing. The 'direction' parameter must
     * be in the range [0..3].
     */
    public void setDirection(int direction)
    {
        if ((direction >= 0) && (direction <= 3)) {
            setRotation(direction * 90);
        }
    }
    
    /**
     * Test if we can move forward. Return true if we can, false otherwise.
     */
    public boolean canMove()
    {
        int rotation = getRotation();
        int x = getX();
        int y = getY();
        boolean facingEdge = false;
        
        switch (rotation) {
            case 0:
                facingEdge = (x == getWorld().getWidth() - 1);
                break;
            case 90:
                facingEdge = (y == getWorld().getHeight() - 1);
                break;
            case 180:
                facingEdge = (x == 0);
                break;
            case 270:
                facingEdge = (y == 0);
                break;
        }
        
        return !facingEdge;
    }
    
    private boolean isPath (Color col)
    {
        return col.getRed() > 160;   // path colour has at least this much red in it
    }
    
    /**
     * Tell how many leaves we have eaten.
     */
    public int getLeavesEaten()
    {
        return leavesEaten;
    }
    
}
