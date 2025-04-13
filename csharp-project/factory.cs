using System;

public abstract class Animal
{
    public abstract string Speak();
}

public class Dog : Animal
{
    public override string Speak()
    {
        return "Woof!";
    }
}

public class Cat : Animal
{
    public override string Speak()
    {
        return "Meow!";
    }
}

public class AnimalFactory
{
    public Animal CreateAnimal(string animalType)
    {
        if (animalType == "dog")
        {
            return new Dog();
        }
        else if (animalType == "cat")
        {
            return new Cat();
        }
        else
        {
            throw new ArgumentException("Invalid animal type");
        }
    }
}

class Program
{
    static void Main()
    {
        AnimalFactory factory = new AnimalFactory();

        var dog = factory.CreateAnimal("dog");
        Console.WriteLine($"Dog says: {dog.Speak()}");

        var cat = factory.CreateAnimal("cat");
        Console.WriteLine($"Cat says: {cat.Speak()}");

        try
        {
            var unknown = factory.CreateAnimal("bird");
            Console.WriteLine($"Unknown animal says: {unknown.Speak()}");
        }
        catch (ArgumentException ex)
        {
            Console.WriteLine(ex.Message);
        }
    }
}
