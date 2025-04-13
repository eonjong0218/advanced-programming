open class Coffee {
    open fun cost(): Int {
        return 5
    }
}

open class CoffeeDecorator(private val coffee: Coffee) : Coffee() {
    override fun cost(): Int {
        return coffee.cost()
    }
}

class MilkDecorator(coffee: Coffee) : CoffeeDecorator(coffee) {
    override fun cost(): Int {
        return super.cost() + 2
    }
}

class SugarDecorator(coffee: Coffee) : CoffeeDecorator(coffee) {
    override fun cost(): Int {
        return super.cost() + 1
    }
}

fun main() {
    val coffee = Coffee()
    println("Plain coffee cost: ${coffee.cost()}") // 5

    val coffeeWithMilk = MilkDecorator(coffee)
    println("Coffee with milk cost: ${coffeeWithMilk.cost()}") // 7

    val coffeeWithSugar = SugarDecorator(coffee)
    println("Coffee with sugar cost: ${coffeeWithSugar.cost()}") // 6

    val coffeeWithMilkAndSugar = SugarDecorator(coffeeWithMilk)
    println("Coffee with milk and sugar cost: ${coffeeWithMilkAndSugar.cost()}") // 8
}
        // 우유와 설탕 추가
        Coffee coffeeWithMilkAndSugar = new SugarDecorator(coffeeWithMilk);
        Console.WriteLine("Coffee with milk and sugar cost: " + coffeeWithMilkAndSugar.Cost()); // 8
    }
}
