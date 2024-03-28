from termcolor import colored

__all__ = ["red", "blue", "green", "cyan", "yellow", "magenta"]


def light_yellow(s): return colored(s, "light_yellow")
def red(s): return colored(s, "red")
def blue(s): return colored(s, "blue")
def cyan(s): return colored(s, "cyan")
def green(s): return colored(s, "green")
def yellow(s): return colored(s, "yellow")
def magenta(s): return colored(s, "magenta")
def dark_grey(s): return colored(s, "dark_grey")
def light_grey(s): return colored(s, "light_grey")
def light_magenta(s): return colored(s, "light_magenta")
