import greenfoot.*;  // imports Actor, World, Greenfoot, GreenfootImage

/**
 * A world where wombats live.
 * 
 * @author Michael Kölling
 * @version 2.0
 */
public class WombatWorld extends World
{
    /**
     * Create a new world with 10x10 cells and
     * with a cell size of 60x60 pixels.
     */
    public WombatWorld() 
    {
        super(60, 40, 10);        
        setBackground("cell.jpg");
        
        setPaintOrder(Wombat.class, Leaf.class, Rock.class);  // draw wombat on top of leaf
        populate();
    }

    /**
     * Populate the world with a fixed scenario of wombats and leaves.
     */    
    public void populate()
    {
        
        addObject(new Leaf(),10,10);
        addObject(new Rock(),2,2);
        randomLeaves(10);
        randomRocks(4);
        addObject(new Wombat(), 30, 20);
        addObject(new Wombat(), 6, 6);
        addObject(new Wombat(), 1, 7);
    }
    
    /**
     * Place a number of leaves into the world at random places.
     * The number of leaves can be specified.
     */
    public void randomLeaves(int howMany)
    {
        for (int i=0; i<howMany; i++) {
            Leaf leaf = new Leaf();
            int x = Greenfoot.getRandomNumber(getWidth());
            int y = Greenfoot.getRandomNumber(getHeight());
            addObject(leaf, x, y);
        }
    }
    
    public void randomRocks(int howMany)
    {
        for (int i=0; i<howMany; i++) {
            Rock rock = new Rock();
            int x = Greenfoot.getRandomNumber(getWidth());
            int y = Greenfoot.getRandomNumber(getHeight());
            addObject(rock, x, y);
        }
    }
}