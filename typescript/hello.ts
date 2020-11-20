let str: string = "Hello World!";
console.log(str);

str = String(1);

let n: number = Number(str);
console.log(n);

class Student {
    id: number;
    name?: string;
}

let student: Student = new Student();
student.id=1;