import re, os
import numpy as np

# Define the grammars
grammars = ["json", "lisp", "mathexpr", "while", "xml"]

# Prepare a regex pattern to extract time
pattern_time = re.compile(r"Time spent building grammar: ([\d.]+)s")
pattern_performance = re.compile(r"Recall: ([\d.]+), Precision: ([\d.]+)")
pattern_query = re.compile(r"Parse calls: ([\d.]+), ([\d.]+)")

# Function to read time from a log file
def read_from_log(pattern, file_name, extract):
    try:
        with open(file_name, 'r') as file:
            content = file.read()
            # Search for the time pattern
            match = pattern.search(content)
            if match:
                return extract(match)
    except FileNotFoundError:
        print(f"File {file_name} not found.")
    return None

# Iterate over grammars and their respective log files

print("Grammar & Recall & Precision & F1 & Time & #Queries")

for grammar in grammars:
    times = []
    recalls = []
    precs = []
    queries = []
    
    for i in range(10):  # Assuming files are named 0.log to 9.log
        log_file_path = os.path.join('result', 'arvada-results',f"{grammar}-{i}.log")
        time = read_from_log(pattern_time, log_file_path, 
                             lambda match: float(match.group(1)) )
        eval_file_path = log_file_path + '.eval'
        recall_prec = read_from_log(pattern_performance, eval_file_path,
                                    lambda match: (float(match.group(1)), float(match.group(2))))
        query = read_from_log(pattern_query, log_file_path, 
                             lambda match: float(match.group(2)) )

        if time is not None:
            times.append(time)
            
        if recall_prec is not None:
            recall, prec = recall_prec
            recalls.append(recall)
            precs.append(prec)
            
        if query is not None:
            queries.append(query)
    
    metrics_output = []
    
    formats = [
        lambda ave, std: f"{ave:.2f}±{std:.2f}",
        lambda ave, std: f"{ave:.2f}±{std:.2f}",
        lambda ave, std: f"{ave:.2f}±{std:.2f}",
        lambda ave, std: f"{ave:.0f}±{std:.0f}s",
        lambda ave, std: f"{ave:.0f}±{std:.0f}",
    ]
    
    f1s = [2.0/(1.0/r + 1.0/p) for r, p in zip(recalls, precs)]

    for format, metric_values in zip(formats, [recalls, precs, f1s, times, queries]):
        if metric_values:
            average = np.mean(metric_values)
            standard_deviation = np.std(metric_values, ddof=1)  # ddof=1 for sample standard deviation
            metrics_output.append(format(average, standard_deviation))
        else:
            metrics_output.append("No data")
            
    # Print formatted output
    print(f"{grammar} & {' & '.join(metrics_output)}")