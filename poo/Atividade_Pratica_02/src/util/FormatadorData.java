package util;

import java.time.LocalDate;
import java.time.format.DateTimeFormatter;

public class FormatadorData {
	private static final DateTimeFormatter FORMATTER = DateTimeFormatter.ofPattern("dd/MM/yyyy");

	public static LocalDate converterData(String dataStr) {
		return LocalDate.parse(dataStr, FORMATTER);
	}
}
