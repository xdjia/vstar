import logging

logging.basicConfig(level=logging.INFO, format='%(funcName)s - %(message)s')

# NOTE - use this to print path and line number to functions
# logging.basicConfig(level=logging.INFO, 
#   format='%(pathname)s:%(lineno)d - %(funcName)s - %(message)s')

logger = logging.getLogger(__name__)
