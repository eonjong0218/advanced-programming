using System;

class Calculator
{
    private double result;

    public Calculator()
    {
        result = 0;
    }

    public Calculator Add(double value)
    {
        result += value;
        return this; // 자기 자신 반환
    }

    public Calculator Subtract(double value)
    {
        result -= value;
        return this; // 자기 자신 반환
    }

    public Calculator Multiply(double value)
    {
        result *= value;
        return this; // 자기 자신 반환
    }

    public Calculator Divide(double value)
    {
        if (value != 0)
        {
            result /= value;
        }
        return this; // 자기 자신 반환
    }

    public double GetResult()
    {
        return result;
    }
}

class Program
{
    static void Main(string[] args)
    {
        Calculator calc = new Calculator();
        double result = calc.Add(5)
                            .Multiply(2)
                            .Subtract(3)
                            .Divide(2)
                            .GetResult();

        Console.WriteLine(result); // 출력: 4
    }
}