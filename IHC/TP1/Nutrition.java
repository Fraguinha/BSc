/**
 * Nutrition
 */
public class Nutrition {

  public static void main(String[] args) {
    FileIN f = new FileIN("nutrition.txt");

    f.open();

    String[] lines = f.readAll();

    f.close();

    float[] vSum = { 0, 0, 0, 0, 0, 0, 0 };
    for (String line : lines) {
      String[] v = line.split("[|]");
      boolean isFirst = line.equals(lines[0]);
      if (isFirst) {
        for (int i = 0; i < 166; i++) {
          System.out.printf("-");
        }
        System.out.println();
        System.out.printf("%-40s %20s %20s %20s %20s %20s %20s\n", v[0], v[1], v[2], v[3], v[4], v[5], "kcal/100g");
        for (int i = 0; i < 166; i++) {
          System.out.printf("-");
        }
        System.out.println();
      } else {
        int kcal = (int) ((Float.parseFloat(v[5]) / Float.parseFloat(v[3])) * 100);
        System.out.printf("%-40s %20s %20s %20s %20s %20s %20d\n", v[0], v[1], v[2], v[3], v[4], v[5], kcal);
        vSum[0] += 1;
        for (int i = 1; i < 7; i++) {
          try {
            vSum[i] += Float.parseFloat(v[i]);
          } catch (Exception e) {
          }
        }

      }
    }
    for (int i = 1; i < 7; i++) {
      vSum[i] = vSum[i] / vSum[0];
    }
    for (int i = 0; i < 166; i++) {
      System.out.printf("-");
    }
    System.out.println();
    System.out.printf("%-40s %20.1f %20s %20.1f %20.1f %20.1f %20.1f\n", "Average", vSum[1], "---", vSum[3], vSum[4],
        vSum[5], vSum[6]);
    for (int i = 0; i < 166; i++) {
      System.out.printf("-");
    }
    System.out.println();
  }
}
