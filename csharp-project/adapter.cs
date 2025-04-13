using System;

class InternalClass
{
    public string Fetch()
    {
        return "get user info";
    }
}

class ExternalClass
{
    public string Search()
    {
        return "get user info";
    }
}

class Adapter
{
    private ExternalClass external;

    public Adapter(ExternalClass external)
    {
        this.external = external;
    }

    public string Fetch()
    {
        return external.Search();
    }
}

class Program
{
    static void Main(string[] args)
    {
        InternalClass internalClass = new InternalClass();
        Console.WriteLine(internalClass.Fetch());

        ExternalClass externalClass = new ExternalClass();
        Adapter adapter = new Adapter(externalClass);
        Console.WriteLine(adapter.Fetch());
    }
}