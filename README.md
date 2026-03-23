# smart_home_energy_load_management_system_c
Smart Home Energy Load Management System
This project is a command-line tool designed to help users track and manage the energy footprint of their household appliances.
Developed as a multidisciplinary engineering project, it focuses on providing a lightweight, efficient way to log power ratings and calculate total daily loads.

Key Technical Featrues:
  * Modular Architecture: Separation of concerns using main.c, backend.c, and backend.h
  * Memory Efficiency: Utilizes realloc and malloc for dynamic data handling of appliance records
  * Advanced Logic: Implements Recursion for energy summation and Unions for flexible power unit handling (Watts/kW).
  * Data Persistence: Integrated binary file handling (.bin) to save and load user data across sessions.
