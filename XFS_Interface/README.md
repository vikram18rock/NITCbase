# XFS Interface

Welcome to the XFS Interface for NITCbase. This section provides information on how to report and manage bugs, issues, and contributions related to the XFS Interface component.

## Usage and Build

The XFS Interface is a vital part of NITCbase, responsible for performing operations directly on the disk without creating a run copy. To build and use the XFS Interface, follow these steps:

1. **Navigate to the XFS_Interface Directory**: First, go to the XFS_Interface directory of your project:

    ```sh
    cd NITCbase/XFS_Interface
    ```

2. **Build the XFS Interface**: You can build the XFS Interface using the `make` command. Here are the available options:

    This command will build the XFS Interface.
    ```sh 
    make
    ``` 

    Use this command to create a gdb debuggable `xfs-interface-debug`.
    ```sh
    make debug
    ```

    If needed, you can clean any previous builds with this command.
    ```sh
    make clean
    ```

3. **Use the XFS Interface**: After building, you can use the XFS Interface to interact with the disk directly. Please note that it operates without creating a run copy, so exercise caution when using it.

## Reporting Bugs and Issues

We appreciate your help in identifying and resolving issues within the XFS Interface. If you come across a bug or have an issue to report, please follow the bug reporting steps as described in the previous section.

## Contributing

If you'd like to contribute to the development of the XFS Interface, please follow the [Contribution Guidelines](../CONTRIBUTING.md) found in the root of the NITCbase repository. This includes details on how to create and submit pull requests.

## License

The XFS Interface follows the same licensing terms as the NITCbase project. Please refer to the [LICENSE](../LICENSE) file for details.

Thank you for your interest in the XFS Interface and your contributions to making it better!
