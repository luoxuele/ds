
class Node{
    constructor(element=null){
        this.element = element;
        this.next = next;
    }
}

export default class LinkedList{
    constructor(head=null) {
        this.head = new Node(head);
        this.length = 0 //Number(Boolean(head)); //创建的时候有传入一个结点，长度加1
        this.tail = null;
    }
    push(element){
        let tmpNode = new Node(element);
        let current = this.head;
        if(current.next){
            while(current.next){
                current = current.next;
            }
        }

        current.next = tmpNode;
        this.length++;
    }

    insert(element,index){

        //支持倒着数
        if(index < 0){
            index = this.length + index;
        }
        //删除的索引必须正确[0，this.lenght-1]
        if(index > this.length || index < 0){
            return 0;
        }


        let tempNode = new Node(element);
        let current = this.head;
        while(index--){
            current = current.next;
        }

        tempNode.next = current.next;
        current.next = tempNode;

        this.length++;

        return 1;

    }

    delete(pos){
        // if(pos<0 || pos>=this.length){
        //     return 0;
        // }
        //支持倒着数
        if(pos<0){
            pos = this.length + pos;
        }
        //删除的索引必须正确[0，this.lenght-1]
        if(pos >= this.length || pos < 0){
            return 0;
        }

        let current = this.head;
        while(pos--){
            current = current.next;
        }
        let ret = current.next;
        current.next = current.next.next;

        this.length--;

        return ret.element;
    }

    travel(){
        let current = this.head;
        while(current.next){
            current = current.next;
            console.log(current.element);
        }
    }

}
