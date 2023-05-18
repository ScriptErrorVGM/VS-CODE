import greenfoot.*;  // (World, Actor, GreenfootImage, Greenfoot and MouseInfo)

/**
 * Write a description of class Car here.
 * 
 * @author (your name) 
 * @version (a version number or a date)
 */
public class Car extends Actor
{
    private GreenfootImage image1;
    int speed = 0;
    int dr = 0;
    final int MAX_SPEED = 4;
    final int MIN_SPEED = -4;
    final int DELAY = 20;
    GreenfootSound turn = new GreenfootSound("turn_2 .wav");
    
    /**
     * Act - do whatever the Car wants to do. This method is called whenever
     * the 'Act' or 'Run' button gets pressed in the environment.
     */
    public Car(){
        
        image1 = new GreenfootImage("car02.png");
        
        setImage("car02.png");
        Greenfoot.playSound("door.mp3");
    }
    
    public void act()
    {
        checkKeypress();
        move(speed);
        checkBarrier();
    }
    
    public void checkEngine(){
        if(speed == 0){
            Greenfoot.playSound("engine_rev.mp3");
            Greenfoot.delay(100);
        } 
    }
    
    public void brakeSound(){
        if(speed == 0){
            Greenfoot.playSound("handbrake.wav");
            Greenfoot.delay(10);
        }
    }
    
    public void checkBarrier(){
        MyWorld world = (MyWorld) getWorld();  
        if (isTouching(Barrier.class) ) {
            world.addObject(new crash(), getX(), getY());
            world.removeObject(this);

            Greenfoot.playSound("car_crash_sound.mp3");   
            world.gameOver();
        }
    }
    
    public void checkKeypress()
    {   
        
        if (Greenfoot.isKeyDown("space")) 
        {
            speed = 0;
            brakeSound();
        }
        if (Greenfoot.isKeyDown("up") && speed < MAX_SPEED )
        {
            checkEngine();
            move(speed++);
            brakeSound();
        }
        if (Greenfoot.isKeyDown("down") && speed > MIN_SPEED )
        {
            move(speed--);
            brakeSound();
        }
        if (Greenfoot.isKeyDown("left") && speed != 0) 
        {
            turn(-1-speed);
            if(!turn.isPlaying()){
                turn.setVolume(90);
                turn.play();
            }
        }
        if (Greenfoot.isKeyDown("right") && speed != 0) 
        {
            turn(1+speed);
            if(!turn.isPlaying()){
                turn.setVolume(90);
                turn.play();
            }
        }
    }
    
}
