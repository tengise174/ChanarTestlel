import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.util.HashMap;
import java.util.Map;
import java.util.regex.Matcher;
import java.util.regex.Pattern;

public class OperatorOperandCounter {

    private static final String[] OPERATORS = { "+", "-", "*", "/", "%", "=", "==", "!=", ">", "<", ">=", "<=", "&&", "||", "!" };
    private static final Pattern OPERAND_PATTERN = Pattern.compile("\\b[a-zA-Z_][a-zA-Z0-9_]*\\b|\\b\\d+\\b");

    private static final String FILE_NAME = "1.txt";

    public static void main(String[] args) {
        Map<String, Integer> operatorCount = new HashMap<>();
        int operandCount = 0;

        for (String operator : OPERATORS) {
            operatorCount.put(operator, 0);
        }

        try (BufferedReader reader = new BufferedReader(new FileReader(FILE_NAME))) {
            String line;
            while ((line = reader.readLine()) != null) {
                for (String operator : OPERATORS) {
                    int index = 0;
                    while ((index = line.indexOf(operator, index)) != -1) {
                        operatorCount.put(operator, operatorCount.get(operator) + 1);
                        index += operator.length();
                    }
                }

                Matcher matcher = OPERAND_PATTERN.matcher(line);
                while (matcher.find()) {
                    operandCount++;
                }
            }
        } catch (IOException e) {
            System.err.println("Error reading file: " + e.getMessage());
        }

        System.out.println("Operators count:");
        for (Map.Entry<String, Integer> entry : operatorCount.entrySet()) {
            if (entry.getValue() > 0) {
                System.out.println(entry.getKey() + ": " + entry.getValue());
            }
        }

        System.out.println("Total operands count: " + operandCount);
    }
}
