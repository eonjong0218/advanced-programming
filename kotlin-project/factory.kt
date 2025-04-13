interface Animal {
    fun speak(): String
}

class Dog : Animal {
    override fun speak(): String {
        return "Woof!"
    }
}

class Cat : Animal {
    override fun speak(): String {
        return "Meow!"
    }
}

class AnimalFactory {
    fun createAnimal(animalType: String): Animal? {
        return when (animalType.lowercase()) {
            "dog" -> Dog()
            "cat" -> Cat()
            else -> null
        }
    }
}

fun main() {
    val factory = AnimalFactory()

    val dog = factory.createAnimal("dog")
    if (dog != null) {
        println("Dog says: ${dog.speak()}")
    }

    val cat = factory.createAnimal("cat")
    if (cat != null) {
        println("Cat says: ${cat.speak()}")
    }

    val unknown = factory.createAnimal("bird")
    if (unknown == null) {
        println("Unknown animal type!")
    }
}