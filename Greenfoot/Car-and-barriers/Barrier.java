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
        //image = new GreenfootImage("Conus.png");
        GreenfootImage image = new GreenfootImage("Conus.png");
        //GreenfootImage image = getImage();
        
        
        image.scale(5,5);
        setImage(image);
        //setImage(image1);
        //setImage("Couns.png");
    }
    
    public void act()
    {
        //checkBarrier();
    }
    
    public void checkBarrier(){
        if (isTouching(Car.class) ) {
            removeTouching(Car.class);
            Greenfoot.playSound("car_crash_sound.mp3");
            //speed = 0;
            //move(speed);
            MyWorld world = (MyWorld) getWorld();
            world.addObject(new crash(), getX(), getY());
            //world.removeObject(this);
            world.gameOver();
            Greenfoot.stop();
        }
    }
}
