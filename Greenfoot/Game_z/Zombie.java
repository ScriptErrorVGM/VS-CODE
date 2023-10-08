import greenfoot.*;  // (World, Actor, GreenfootImage, Greenfoot and MouseInfo)

/**
 * Write a description of class Zombie here.
 * 
 * @author (your name) 
 * @version (a version number or a date)
 */
public class Zombie extends Actor
{
    /**
     * Act - do whatever the Zombie wants to do. This method is called whenever
     * the 'Act' or 'Run' button gets pressed in the environment.
     */
    int animateImage = 0;
    int animateSpeed = 7;
    int count = 0;
    int health = 2;
    Player player;
    Counter counter;
    public Zombie(Player mainPlayer, Counter counter)
    {
        this.counter = counter;
        player = mainPlayer;
        setImage("idle0000.png");
        getImage().scale(160,160);
    }
    public void act()
    {
        count++;
        animate();
        moveAround();
        hitByProjectile();
        // Add your action code here.
    }
    //animate
    public void animate()
    {
        if(count % animateSpeed == 0)
        {
            if(animateImage > 28){
                animateImage = 0;
            }
            setImage("walk" + animateImage + ".png");
            animateImage++;
            getImage().scale(160,160);
        }
    
    }
    
    public void moveAround()
    {
        move(1);
        turnTowards(player.getX(), player.getY());
    }
    
    public void hitByProjectile()
    {
        Actor projectile = getOneIntersectingObject(Projectile.class);
        if(projectile != null)
        {
            health--;
            getWorld().removeObject(projectile);
        }
        if(health == 0){
            counter.score++;  
            counter.money+=5;
            getWorld().removeObject(this);
        }
    }
}
