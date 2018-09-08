# Java小数点位数保留

* [Java小数点位数保留](https://www.jianshu.com/p/00fff555986b)

* 使用DecimalFormat类的format方法。
  ```java
  double d = 3.14159;
  String s = new DecimalFormat("0.00").format(d);
  ```
* 使用String的format方法。
  ```java
  double d = 3.14159;
  String s = String.format("%.2f",d);
  ```
* 使用BigDecimal类
  ```
  double d = 1.000;
  BigDecimal bd=new BigDecimal(d);
  double d1=bd.setScale(2,BigDecimal.ROUND_HALF_UP).doubleValue();
  System.out.println(d1);
  ```
