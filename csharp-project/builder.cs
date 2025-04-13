using System;

class Person
{
    public string Name { get; set; }
    public int Age { get; set; }
    public string Address { get; set; }

    public Person()
    {
        Name = string.Empty;
        Age = 0;
        Address = string.Empty;
    }
}

class PersonBuilder
{
    private Person person;

    public PersonBuilder()
    {
        person = new Person();
    }

    public PersonBuilder WithName(string name)
    {
        person.Name = name;
        return this; // 자기 자신 반환
    }

    public PersonBuilder WithAge(int age)
    {
        person.Age = age;
        return this; // 자기 자신 반환
    }

    public PersonBuilder WithAddress(string address)
    {
        person.Address = address;
        return this; // 자기 자신 반환
    }

    public Person Build()
    {
        return person;
    }
}

class Program
{
    static void Main(string[] args)
    {
        Person person = new PersonBuilder()
            .WithName("홍길동")
            .WithAge(20)
            .WithAddress("양산시 부산대학로")
            .Build();

        Console.WriteLine($"Name: {person.Name}");
        Console.WriteLine($"Age: {person.Age}");
        Console.WriteLine($"Address: {person.Address}");
    }
}