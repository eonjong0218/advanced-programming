// 기본 커피 클래스
open class Coffee {
    open fun cost(): Int {
        return 5
    }
}

// 데코레이터 기본 클래스
open class CoffeeDecorator(private val coffee: Coffee) : Coffee() {
    override fun cost(): Int {
        return coffee.cost()
    }
}

// 우유 추가 데코레이터
class MilkDecorator(coffee: Coffee) : CoffeeDecorator(coffee) {
    override fun cost(): Int {
        return super.cost() + 2
    }
}

// 설탕 추가 데코레이터
class SugarDecorator(coffee: Coffee) : CoffeeDecorator(coffee) {
    override fun cost(): Int {
        return super.cost() + 1
    }
}

// 실행 메인 함수
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
