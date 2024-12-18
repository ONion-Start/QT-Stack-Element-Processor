# Stack Element Processor

Stack Element Processor — это приложение для обработки набора чисел, используя стек. Программа читает числа из файла, обрабатывает их, меняя порядок пар элементов, и записывает результат в новый файл.

## Описание проекта

Программа выполняет следующие задачи:

1. Загружает числа из файла `input.txt` в стек.
2. Меняет порядок у каждой четвёрки элементов в стеке:
   - Первая пара элементов меняется местами со второй парой.
3. Записывает результаты в новый файл `output.txt`.
4. Предоставляет графический интерфейс для генерации, сохранения и обработки данных.

## Основные функции

- **Генерация случайных чисел**:
  - Генерирует заданное количество случайных чисел и отображает их в таблице.

- **Сохранение входных данных**:
  - Сохраняет сгенерированные числа в файл `input.txt`.

- **Обработка данных**:
  - Загружает числа из таблицы в стек.
  - Меняет порядок пар элементов в стеке.
  - Отображает обработанные данные в выходной таблице.

- **Сохранение выходных данных**:
  - Сохраняет обработанные данные в файл `output.txt`.

## Используемые технологии

- **C++**: Логика приложения.
- **Qt Framework**: Создание графического интерфейса.

## Сборка и запуск

### Требования

- Qt версии 5.12 или выше.
- Компилятор, поддерживающий стандарт C++11 или выше.

### Инструкции по сборке

1. Склонируйте репозиторий:
   ```bash
   git clone https://github.com/<ваш-репозиторий>/stack-element-processor.git
   ```

2. Откройте проектный файл в Qt Creator.

3. Соберите и запустите проект.

## Как использовать

1. Запустите приложение.
2. Сгенерируйте числа с помощью кнопки "Generate" или загрузите свои данные в таблицу.
3. Нажмите кнопку "Save Input" для сохранения входных данных в файл `input.txt`.
4. Нажмите кнопку "Process" для обработки данных. Результат отобразится в выходной таблице.
5. Нажмите кнопку "Save Output" для сохранения обработанных данных в файл `output.txt`.

## Пример работы

### Входные данные:
```
1 2 3 4 5 6 7 8
```

### Обработанные данные:
```
3 4 1 2 7 8 5 6
```

## Лицензия

Проект распространяется под лицензией MIT. Подробнее см. файл LICENSE.

