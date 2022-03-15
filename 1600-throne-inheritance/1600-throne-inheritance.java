class Person {
    public String name;
    public List<Person> children;
    public boolean isDead;
    
    public Person(String name) {
        this.name = name;
        this.children = new ArrayList<>();
        this.isDead = false;
    }
    
    public Person addChild(String name) {
        Person child = new Person(name);
        this.children.add(child);
        return child;
    }
    
    public void setDead() {
        this.isDead = true;
    }
    public boolean getDead() {
        return this.isDead;
    }
    
    public List<String> getInheritance(List<String> result) {
        if (!this.getDead()) {
            result.add(this.name);
        }
        for (Person p: this.children) {
            p.getInheritance(result);
        }
        return result;
    }
}

class ThroneInheritance {

    Person king;
    Map<String, Person> nameToPerson;
    
    public ThroneInheritance(String kingName) {
        this.king = new Person(kingName);
        this.nameToPerson = new HashMap<>();
        this.nameToPerson.put(kingName, this.king);
    }
    
    public void birth(String parentName, String childName) {
        Person person = nameToPerson.get(parentName);
        Person child = person.addChild(childName);
        nameToPerson.put(childName, child);
    }
    
    public void death(String name) {
        Person person = nameToPerson.get(name);
        person.setDead();
    }
    
    public List<String> getInheritanceOrder() {
        List<String> result = new ArrayList<>();
        king.getInheritance(result);
        return result;
    }
}
/**
 * Your ThroneInheritance object will be instantiated and called as such:
 * ThroneInheritance obj = new ThroneInheritance(kingName);
 * obj.birth(parentName,childName);
 * obj.death(name);
 * List<String> param_3 = obj.getInheritanceOrder();
 */