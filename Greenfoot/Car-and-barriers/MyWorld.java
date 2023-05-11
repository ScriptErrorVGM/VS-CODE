import greenfoot.*;  // (World, Actor, GreenfootImage, Greenfoot and MouseInfo)

/**
 * Write a description of class MyWorld here.
 * 
 * @author (your name) 
 * @version (a version number or a date)
 */
public class MyWorld extends World
{

    /**
     * Constructor for objects of class MyWorld.
     * 
     */
    public MyWorld()
    {    
        // Create a new world with 600x400 cells with a cell size of 1x1 pixels.
        super(800, 600, 1);
        setBackground("asphalt.jpg");
        create();
    }
    
    public void create() {
        addObject(new Car(),200,200);
        
        addObject(new Barrier(),100,150);
        addObject(new Barrier(),240,150);
        
        addObject(new Barrier(),270,210);
        addObject(new Barrier(),160,290);
        
        addObject(new Barrier(),330,250);
        addObject(new Barrier(),310,380);
        
        addObject(new Barrier(),420,230);
        addObject(new Barrier(),420,360);
        
        addObject(new Barrier(),500,210);
        addObject(new Barrier(),500,340);
        
        addObject(new Barrier(),650,280);
        addObject(new Barrier(),560,380);
        
        addObject(new Barrier(),730,440);
        addObject(new Barrier(),590,440);
    }
}
